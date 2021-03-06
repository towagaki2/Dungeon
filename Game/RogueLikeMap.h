#pragma once
#include <cstdint>
#include <vector>
#include <random>
//自作のマップデータを扱えます
class RogueLikeMap
{
public:
	RogueLikeMap(const size_t var_) :mapData(var_)
	{
	}
	RogueLikeMap() = default;
	~RogueLikeMap();
	std::vector<std::vector<RogueLikeMap>> NewMap();
	//書き換え可能なマップ
	size_t mapData = 1;
	size_t size = 1;
	size_t roomNo= 0;

};

enum :int {
	RL_COUNT_X,
	RL_COUNT_Y
};

struct DungeonMap_RL
{

	//生成される部屋の数 (正確に言うと生成される区域の数)
	size_t divCountMin = 5; //マップの区分け最小数
	size_t divCountRand = 2; //マップの区分け数加算

							 //生成される部屋のサイズ
	size_t roomLengthMinX = 5; //部屋のX座標の最小サイズ
	size_t roomLengthMinY = 5; //部屋のY座標の最小サイズ
	size_t roomLengthRandX = 10; //部屋のX座標のサイズ加算
	size_t roomLengthRandY = 10; //部屋のY座標のサイズ加算

	size_t mapDivCount{}; //マップの区分け数 (部屋の個数) 0~nまでの部屋ID
	size_t mapDiv[8][4]{}; //マップの区域 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
	size_t mapRoom[8][4]{}; //マップの部屋 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
	size_t mapRoad[8][4]{}; //マップの道 [部屋ID(前)][繋がる先の部屋ID(後) , (0.X座標 , 1.Y座標) , (前)側の通路の位置 , (後)側の通路の位置]
	size_t mapRoomPlayer[8]{};

};

/*ローグライク生成関数*/
template <typename T>
int rogueLikeMapMake(DungeonMap_RL* const dng, T& maprl)
{
	std::random_device rnd;     // 非決定的な乱数生成器を生成
	std::mt19937 Rand(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
	std::uniform_int_distribution<> GetRand(0, 10000);        // [0, 10000] 範囲の一様乱数
	if (maprl.size() == 0 || maprl.front().size() == 0) return -1;
	dng->mapDivCount = dng->divCountMin + (size_t)(GetRand(Rand) * ((int)(dng->divCountRand)+1)/ (1 + 10000)); //マップの区分け数 (部屋の個数) 0~nまでの部屋ID
	for (size_t i = 0; i < maprl.size(); ++i)
		for (size_t j = 0; j < maprl[i].size(); ++j) {
			maprl[i][j].mapData = 1;
			maprl[i][j].size = dng->mapDivCount;
		}
	if (dng->mapDivCount > 7) return -1;

	dng->mapDiv[0][0] = (maprl.size() - 1); //マップの区分け初期サイズX終点 (マップの大きさX軸)
	dng->mapDiv[0][1] = (maprl.front().size() - 1); //マップの区分け初期サイズY終点 (マップの大きさY軸)
	dng->mapDiv[0][2] = 1; //マップの区分け初期サイズX始点 (マップの大きさX軸)
	dng->mapDiv[0][3] = 1; //マップの区分け初期サイズY始点 (マップの大きさY軸)

	dng->mapRoad[0][0] = 255;
	dng->mapRoad[0][1] = 255;

	/*マップを区分けしていく処理(区域を分割する処理)*/
	size_t divAfter;
	int count; //(0:X, 1:Y) X軸で分けるかY軸で分けるか決める

	for (size_t i = 1; i < dng->mapDivCount; ++i) {

		//今まで作った区分けをランダムに指定(指定した区域をさらに区分けする)
		divAfter = (size_t)(GetRand(Rand)*(i-1 + 1) / (1 + 10000));

		//指定した区域のXとYの長さによって、分割する向きを決める(長いほうを分割する)
		if (dng->mapDiv[divAfter][0] - dng->mapDiv[divAfter][2] > dng->mapDiv[divAfter][1] - dng->mapDiv[divAfter][3]) count = RL_COUNT_X;
		else count = RL_COUNT_Y;

		if (dng->mapDiv[divAfter][count] - dng->mapDiv[divAfter][count + 2] < dng->divCountRand * 2 + 8) {
			size_t k = 0;
			for (size_t j = 1; j < dng->mapDivCount; ++j) {
				if (dng->mapDiv[j][0] - dng->mapDiv[j][2] > k) {
					k = dng->mapDiv[j][0] - dng->mapDiv[j][2];
					divAfter = j;
					count = RL_COUNT_X;
				}
				if (dng->mapDiv[j][1] - dng->mapDiv[j][3] > k) {
					k = dng->mapDiv[j][1] - dng->mapDiv[j][3];
					divAfter = j;
					count = RL_COUNT_Y;
				}
			}
		}

		dng->mapRoad[i][0] = divAfter;
		dng->mapRoad[i][1] = count;

		for (size_t j = 1; j < i; ++j)
			if (dng->mapRoad[j][0] == divAfter) dng->mapRoad[j][0] = i;

		//count軸の設定
		dng->mapDiv[i][count] = dng->mapDiv[divAfter][count + 2] + (dng->mapDiv[divAfter][count] - dng->mapDiv[divAfter][count + 2]) / 3 + (size_t)(GetRand(Rand) * (int)(((dng->mapDiv[divAfter][count] - dng->mapDiv[divAfter][count + 2]) / 3)+1) / (1 + 10000)); //0.軸の右端(iR)の座標(divAfter*R/3~2divAfter*R/3)
		dng->mapDiv[i][count + 2] = dng->mapDiv[divAfter][count + 2]; //0.軸の左端(iL)の座標(divAfterL)
		dng->mapDiv[divAfter][count + 2] = dng->mapDiv[i][count]; //divAfter軸の左端(divAfterL)の座標(iR)

																  //countとは逆の軸の設定
		dng->mapDiv[i][abs(count - 1)] = dng->mapDiv[divAfter][abs(count - 1)]; //軸の右端(iR)の座標(divAfterR)
		dng->mapDiv[i][abs(count - 1) + 2] = dng->mapDiv[divAfter][abs(count - 1) + 2]; //軸の左端(iL)の座標(divAfterL)
	}

	/*部屋を生成する処理*/
	for (size_t i = 0; i < dng->mapDivCount; ++i) {//区分け
		dng->mapRoomPlayer[i] = 0;//プレイヤー侵入初期化
		dng->mapRoom[i][2] = dng->mapDiv[i][2]; //区分けX始点をマップX始点へ代入
		dng->mapRoom[i][3] = dng->mapDiv[i][3]; //区分けY始点をマップY始点へ代入
												//X座標の部屋の長さを指定
		dng->mapRoom[i][0] = dng->mapDiv[i][2] + dng->divCountRand + (size_t)(GetRand(Rand) * ((int)(dng->roomLengthRandX)+1)/(1+ 10000));
		if (dng->mapDiv[i][0] - dng->mapDiv[i][2] < dng->mapRoom[i][0] - dng->mapRoom[i][2] + 5) {
			dng->mapRoom[i][0] = dng->mapDiv[i][0] - 4;
			if (dng->mapDiv[i][0] - dng->mapDiv[i][2] < dng->mapRoom[i][0] - dng->mapRoom[i][2] + 5) {
				dng->mapRoom[i][0] = dng->mapDiv[i][2] + 1;
			}
		}

		dng->mapRoom[i][1] = dng->mapDiv[i][3] + dng->roomLengthMinY + (size_t)(GetRand(Rand) * ((int)(dng->roomLengthRandY)+1)/(1+ 10000));
		if (dng->mapDiv[i][1] - dng->mapDiv[i][3] < dng->mapRoom[i][1] - dng->mapRoom[i][3] + 5) {
			dng->mapRoom[i][1] = dng->mapDiv[i][1] - 4;
			if (dng->mapDiv[i][1] - dng->mapDiv[i][3] < dng->mapRoom[i][1] - dng->mapRoom[i][3] + 5) {
				dng->mapRoom[i][1] = dng->mapDiv[i][3] + 1;
			}
		}

		if (dng->mapRoom[i][0] - dng->mapDiv[i][2] <= 1 || dng->mapRoom[i][1] - dng->mapDiv[i][3] <= 1) {
			dng->mapRoom[i][0] = dng->mapDiv[i][2] + 1;
			dng->mapRoom[i][1] = dng->mapDiv[i][3] + 1;
		}
		size_t l;
		size_t m;
		auto k=GetRand(Rand);
		l = (size_t)(2+k * (((int)dng->mapDiv[i][0] - (int)dng->mapRoom[i][0] - 5)+1) / (1 + 10000));
		
		auto nn = GetRand(Rand);
		m = (size_t)(2 + nn * (((int)dng->mapDiv[i][1] - (int)dng->mapRoom[i][1] - 5)+1)/ (1 + 10000));
		dng->mapRoom[i][0] += l;
		dng->mapRoom[i][2] += l;
		dng->mapRoom[i][1] += m;
		dng->mapRoom[i][3] += m;

		for (size_t j = dng->mapRoom[i][2]; j < dng->mapRoom[i][0]; ++j)
			for (size_t k = dng->mapRoom[i][3]; k < dng->mapRoom[i][1]; ++k) {
				maprl[j][k].mapData = 0;
				maprl[j][k].roomNo = i+1;
			}

	}


	/*通路を生成する処理*/
	/*通路は２部屋間の細い道のことを指す。
	通路を作るために２部屋をそれぞれ前(Before)と後(After)で分ける。
	for文で全ての部屋をチェックし、前後の部屋を繋ぐ通路を作る。
	まず、前の通路を作り、次に後の通路を作る。
	最後に前と後の通路を繋げる。
	*/
	size_t roomAfter;
	for (size_t roomBefore = 0; roomBefore < dng->mapDivCount; ++roomBefore) {
		roomAfter = dng->mapRoad[roomBefore][0];

		//X座標の通路
		switch (dng->mapRoad[roomBefore][1]) {
		case RL_COUNT_X:
			dng->mapRoad[roomBefore][2] = (size_t)( GetRand(Rand) * ((int)(dng->mapRoom[roomBefore][1] - dng->mapRoom[roomBefore][3]) - 2 +1)/ (1 + 10000)); //前側の通路の位置
			dng->mapRoad[roomBefore][3] = (size_t)( GetRand(Rand) * ((int)(dng->mapRoom[roomAfter][1] - dng->mapRoom[roomAfter][3] ) - 2 +1) / (1 + 10000)) ; //後側の通路の位置
																															   //前の通路
			for (size_t j = dng->mapRoom[roomBefore][0]; j < dng->mapDiv[roomBefore][0]; ++j)
				maprl[j][dng->mapRoad[roomBefore][2] + dng->mapRoom[roomBefore][3]].mapData = 0; //通路をマップチップに線画

																								 //後の通路
			for (size_t j = dng->mapDiv[roomAfter][2]; j < dng->mapRoom[roomAfter][2]; ++j)
				maprl[j][dng->mapRoad[roomBefore][3] + dng->mapRoom[roomAfter][3]].mapData = 0; //通路をマップチップに線画

																								//通路をつなぐ
			for (size_t j = dng->mapRoad[roomBefore][2] + dng->mapRoom[roomBefore][3]; j <= dng->mapRoad[roomBefore][3] + dng->mapRoom[roomAfter][3]; ++j)
				maprl[dng->mapDiv[roomBefore][0]][j].mapData = 0; //通路をマップチップに線画 2から5(上から下)
			for (size_t j = dng->mapRoad[roomBefore][3] + dng->mapRoom[roomAfter][3]; j <= dng->mapRoad[roomBefore][2] + dng->mapRoom[roomBefore][3]; ++j)
				maprl[dng->mapDiv[roomBefore][0]][j].mapData = 0; //通路をマップチップに線画 5から2(下から上)
			break;

		case RL_COUNT_Y:
			dng->mapRoad[roomBefore][2] = (size_t)( GetRand(Rand) * ((int)(dng->mapRoom[roomBefore][0] - dng->mapRoom[roomBefore][2]) - 2 +1)/ (1.0f + 10000)); //前側の通路の位置
			dng->mapRoad[roomBefore][3] = (size_t)( GetRand(Rand) * ((int)(dng->mapRoom[roomAfter][0] - dng->mapRoom[roomAfter][2])-2 + 1) / (1.0f + 10000)); //後側の通路の位置
																															   //前の通路
			for (size_t j = dng->mapRoom[roomBefore][1]; j < dng->mapDiv[roomBefore][1]; ++j)
				maprl[dng->mapRoad[roomBefore][2] + dng->mapRoom[roomBefore][2]][j].mapData = 0; //通路をマップチップに線画

																								 //後の通路
			for (size_t j = dng->mapDiv[roomAfter][3]; j < dng->mapRoom[roomAfter][3]; ++j)
				maprl[dng->mapRoad[roomBefore][3] + dng->mapRoom[roomAfter][2]][j].mapData = 0; //通路をマップチップに線画

																								//通路をつなぐ
			for (size_t j = dng->mapRoad[roomBefore][2] + dng->mapRoom[roomBefore][2]; j <= dng->mapRoad[roomBefore][3] + dng->mapRoom[roomAfter][2]; ++j)
				maprl[j][dng->mapDiv[roomBefore][1]].mapData = 0; //通路をマップチップに線画
			for (size_t j = dng->mapRoad[roomBefore][3] + dng->mapRoom[roomAfter][2]; j <= dng->mapRoad[roomBefore][2] + dng->mapRoom[roomBefore][2]; ++j)
				maprl[j][dng->mapDiv[roomBefore][1]].mapData = 0; //通路をマップチップに線画
			break;
		}

	}
	return 0;
}