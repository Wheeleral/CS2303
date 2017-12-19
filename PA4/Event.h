/*
 * @file Event.h
 * @author Alexandra Wheeler
 * @date 28 Sept 2017
 * @brief  Event object header file
 */

#ifndef EVENT_H_
#define EVENT_H_

class Event {
public:
	int time;
	int duration;

	static int Id;
	int iD;

	Event();
	virtual ~Event();
	virtual void action();

};

#endif /* EVENT_H_ */
