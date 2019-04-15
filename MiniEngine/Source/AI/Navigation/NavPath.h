#pragma once

/**
 * Defines a navigation path connecting to points.
 */
class NavPath
{
public:
	/** Default constructor. */
	NavPath();

	/** Constructor to initialize point indices. */
	NavPath(int From, int To);

	/** Constructor to initializes point indices, and cost. */
	NavPath(int From, int To, int Cost);

	/** Default destructor. */
	virtual ~NavPath();

	/**  */
	void SetFrom(int NewIndex);

	/**  */
	void SetTo(int NewIndex);

	/**  */
	void SetCost(int NewCost);

	/**  */
	inline int GetFrom() const { return m_From; }

	/**  */
	inline int GetTo() const { return m_To; }

	/**  */
	inline double GetCost() { return m_Cost; }

protected:
	/**  */
	int m_From;

	/**  */
	int m_To;

	/**  */
	double m_Cost;
};