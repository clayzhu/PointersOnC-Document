/*
** Structure for long distance telephone billing record.
*/
struct PHONE_NUMBER {
	short	area;
	short	exchange;
	short	station;
};

struct LONG_DISTANCE_BILL {
	short	month;
	short	day;
	short	year;
	int	time;
	struct	PHONE_NUMBER	called;
	struct	PHONE_NUMBER	calling;
	struct	PHONE_NUMBER	billed;
};
