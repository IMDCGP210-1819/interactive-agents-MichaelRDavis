#pragma once

#include "Math/Vector.h"

class NavPath;

/**
 * Represents a single node in the navigation graph.
 */
class NavPoint
{
public:
	/** Default destructor. */
	NavPoint();

	/** Constructor with args.
	*	@param Index - Index of the navigation point.
	*/
	NavPoint(int Index);

	/** Default destructor. */
	virtual ~NavPoint();

	/** Returns the point index. */
	inline int GetIndex() const { return m_Index; }

	/** Set the point index to a new value.
	*	@param NewIndex - New point index value.
	*/
	void SetIndex(int NewIndex);

	/** Returns the position the point in 2D space. */
	inline Vec2 GetPosition() const { return m_Position; }

	/** Set the point position to a new value. 
	*	@param NewPosition - Position to set.
	*/
	void SetPosition(Vec2 NewPosition);

protected:
	/**  */
	float m_Tolerance;

	/** Index of the point. */
	int m_Index;

	/** Position of the point node in 2D space. */
	Vec2 m_Position;

	/** List of navigation paths associated with point. */
	std::list<NavPath*> m_NavPathList;
};