/*
@file Collision.h
@brief 正方形や線、三角形等のオブジェクト宣言
*/

/*
@brief	プリプロセッサ
*/
#pragma once

/*
@brief	インクルード
*/
#include "Math.h"
#include <vector>
#include <map>

//線分
struct LineSegment
{
	/*
	@param	_start 線分の開始地点のポジション
	@param	_end 線分の終了地点のポジション
	*/
    LineSegment(const Vector3& _start, const Vector3& _end);
	
	/*
	@fn		線分上の点を返す
	@param	_t 入力値 t（L(t) = Start + (End - Start)t）
	@return 線分上の点のポジション(Vector3型)
	*/
	Vector3 PointOnSegment(float _t) const;

	/*
	@fn		点と線分の間の最短距離を返す
	@param	_point 任意の点のポジション
	@return 最短距離(float型)
	*/
    float MinDistanceSquared(const Vector3& _point)const;

	/*
	@fn		線分と線分の間の最短距離を返す
	@param	_line1 判定する線分の構造体１
	@param	_line2 判定する線分の構造体２
	@return 最短距離(float型)
	*/
    static float MinDistanceSquared(const LineSegment& _line1,const LineSegment& _line2);

	//線分の開始地点
    Vector3 m_start;
	//線分の終了地点
    Vector3 m_end;
};

//平面
struct Plane
{
	/*
	@param	_normal 平面の法線ベクトル
	@param	_distance 平面と原点の符号つき最短距離
	*/
    Plane(const Vector3& _normal, float _distance);

	/*
	@param	_vec1 平面上の点1
	@param	_vec2 平面上の点2
	@param	_vec3 平面上の点3
	*/
    Plane(const Vector3& _vec1, const Vector3& _vec2, const Vector3& _vec3);

	/*
	@fn		点と平面の最短距離を返す
	@param	_point 任意の点のポジション
	@return 符号つき最短距離(float型)
	*/
    float SignedDistance(const Vector3& _point);

	//平面の法線ベクトル
    Vector3 m_normal;
	//平面と原点の符号つき最短距離
    float m_distance;
};

//球
struct Sphere
{
	/*
	@param	_center 球体の中心座標
	@param	_radius 球体の半径
	*/
    Sphere(const Vector3& _center, const float _radius);
    
	/*
	@fn		球体に点が含まれているかどうか
	@param	_point 任意の点
	@return true : 当たっている , false : 当たっていない(bool型)
	*/
	bool Contains(const Vector3& _point)const;

	//球体の中心座標
    Vector3 m_center;
	//球体の半径
    float m_radius;
};

//軸並行バウンディングボックス(Axis-Aligned Bounding Box)
struct AABB
{
	/*
	@param	_min 最小のx,y,zの値のポジション
	@param	_max 最大のx,y,zの値のポジション
	*/
    AABB(const Vector3& _min,const Vector3& _max);

	/*
	@fn		最小値と最大値を各成分ごとに更新する
	@param	_point 任意の点のポジション
	*/
    void UpdateMinMax(const Vector3& _point);

	/*
	@fn		当たり判定ボックスの回転
	@param	_quaternion 回転軸と回転表す値
	*/
    void Rotate(const Quaternion& _quaternion);
    
	/*
	@fn	ボックスに点が含まれているかどうか
	@param	_point 任意の点
	@return true : 当たっている , false : 当たっていない(bool型)
	*/
	bool Contains(const Vector3& _point)const;
    
	/*
	@fn		点とボックスの最短距離を返す
	@param	_point 任意の点
	@return 最短距離
	*/
	float MinDistanceSquared(const Vector3& _point)const;

	/*
	@fn		最小値と最大値を初期化
	@param	_point 任意の点
	*/
	void InitMinMax(const Vector3& _point) { m_min = m_max = _point; };

	//最小のx,y,zの値のポジション
    Vector3 m_min;
	//最大のx,y,zの値のポジション
    Vector3 m_max;
};

//有向バウンディングボックス（Oriented Bounding Box）
//未実装
struct OBB
{
	//中心の座標
    Vector3 m_center;
	//回転クォータニオン
    Quaternion m_rotation;
	//ボックスの広がり（幅、高さ、奥行き）
    Vector3 m_extents;
};

//カプセル
struct Capsule
{
	/*
	@param	_start 始点となる点の座標
	@param	_end 終点となる点の座標
	@param	_radius カプセルの半径
	*/
    Capsule(const Vector3& _start,const Vector3& _end,float _radius);

	/*
	@fn	カプセルの始点と終点の線分上の点を返す
	@param	_t 入力値 t（L(t) = Start + (End - Start)t）
	@return 線分上の点のポジション(Vector3型)
	*/
    Vector3 PointOnSegment(float _t)const;

	/*
	@fn	カプセルに点が含まれているかどうか
	@param	_point 任意の点
	@return true : 当たっている , false : 当たっていない(bool型)
	*/
    bool Contains(const Vector3& _point)const;

	//カプセルを構成する線分
    LineSegment m_segment;
	//カプセルの半径
    float m_radius;
};

//凸ポリゴン
struct ConvexPolygon
{
	/*
	@fn		２次元のポリゴンに点が含まれているかどうか
	@param	_point 任意の点
	@return true : 当たっている , false : 当たっていない(bool型)
	*/
    bool Contains(const Vector2& _point)const;

	//頂点の可変長コンテナ
    std::vector<Vector2> m_vertices;
};

/*
@fn	球と球の当たり判定
@param	_sphere1 球の構造体１
@param	_sphere2 球の構造体２
@return true : 当たっている , false : 当たっていない(bool型)
*/
bool Intersect(const Sphere& _sphere1,const Sphere& _sphere2);

/*
@fn		ボックスとボックスの当たり判定
@param	_AABB1 ボックスの構造体１
@param	_AABB2 ボックスの構造体２
@return true : 当たっている , false : 当たっていない(bool型)
*/
bool Intersect(const AABB& _AABB1, const AABB& _AABB2);

/*
@fn		カプセルとカプセルの当たり判定
@param	_capsule1 カプセルの構造体１
@param	_capsule2 カプセルの構造体２
@return true : 当たっている , false : 当たっていない(bool型)
*/
bool Intersect(const Capsule& _capsule1, const Capsule& _capsule2);

/*
@fn	球とボックスの当たり判定
@param	_sphere 球の構造体
@param	_AABB ボックスの構造体
@return true : 当たっている , false : 当たっていない(bool型)
*/
bool Intersect(const Sphere& _sphere, const AABB& _AABB);

/*
@fn	線分と球の当たり判定
@param	_line 線分の構造体
@param	_sphere 球の構造体
@param	_outT 線分の始点から接触している点までの値tを格納する
@return true : 当たっている , false : 当たっていない(bool型)
*/
bool Intersect(const LineSegment& _line, const Sphere& _sphere, float& _outT);

/*
@fn	線分と平面の当たり判定
@param	_line　線分の構造体
@param	_plane　平面の構造体
@param	_outT　線分の始点から接触している点までの値tを格納する
@return true : 当たっている , false : 当たっていない(bool型)
*/
bool Intersect(const LineSegment& _line, const Plane& _plane, float& _outT);

/*
@fn	線分とボックスの当たり判定
@param	_line 線分の構造体
@param	_AABB ボックスの構造体
@param	_outT 線分の始点から接触している点までの値tを格納する
@param	_outNorm 線分の始点から接触した面の法線ベクトルを格納する
@return true : 当たっている , false : 当たっていない(bool型)
*/
bool Intersect(const LineSegment& _line, const AABB& _AABB, float& _outT,
    Vector3& _outNorm);

/*
@fn	球スイープの当たり判定
@param	_sphere1 １フレーム前の球１の構造体
@param	_sphere2 現在のフレームの球１の構造体
@param	_sphere3 １フレーム前の球２の構造体
@param	_sphere4 現在のフレームの球２の構造体
@param	_outT 線分の始点から接触している点までの値tを格納する
@return true : 当たっている , false : 当たっていない(bool型)
*/
bool SweptSphere(const Sphere& _sphere1, const Sphere& _sphere2,
    const Sphere& _sphere3, const Sphere& _sphere4, float& _outT);
