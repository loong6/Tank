#ifndef  __TRANSITION_EX_H__
#define  __TRANSITION_EX_H__

#include "cocos2d.h"

USING_NS_CC;

class SplitExA : public TiledGrid3DAction
{
public:

	/**
	* @brief Create the action with the the duration.
	* @param duration Specify the duration of the SplitExA action. It's a value in seconds.
	* @return If the creation success, return a pointer of SplitCols action; otherwise, return nil.
	*/
	static SplitExA* create(float duration);

	// Overrides
	virtual SplitExA* clone() const override;
	/**
	* @param time in seconds
	*/
	virtual void update(float time) override;
	virtual void startWithTarget(Node *target) override;

CC_CONSTRUCTOR_ACCESS:
	SplitExA() {}
	virtual ~SplitExA() {}

	/**
	* @brief Initializes the action with the duration.
	* @param duration Specify the duration of the SplitExA action. It's a value in seconds.
	* @return If the creation success, return true; otherwise, return false.
	*/
	bool initWithDuration(float duration);

protected:
	Size _winSize;

private:
	CC_DISALLOW_COPY_AND_ASSIGN(SplitExA);
};

class SplitExB : public TiledGrid3DAction
{
public:

	/**
	* @brief Create the action with the the duration.
	* @param duration Specify the duration of the SplitExB action. It's a value in seconds.
	* @return If the creation success, return a pointer of SplitCols action; otherwise, return nil.
	*/
	static SplitExB* create(float duration);

	// Overrides
	virtual SplitExB* clone() const override;
	/**
	* @param time in seconds
	*/
	virtual void update(float time) override;
	virtual void startWithTarget(Node *target) override;

CC_CONSTRUCTOR_ACCESS:
	SplitExB() {}
	virtual ~SplitExB() {}

	/**
	* @brief Initializes the action with the duration.
	* @param duration Specify the duration of the SplitExB action. It's a value in seconds.
	* @return If the creation success, return true; otherwise, return false.
	*/
	bool initWithDuration(float duration);

protected:
	Size _winSize;

private:
	CC_DISALLOW_COPY_AND_ASSIGN(SplitExB);
};

/** @class TransitionExA
* @brief TransitionExA:
The odd columns goes upwards while the even columns goes downwards.
*/
class TransitionExA : public TransitionScene
{
public:
	/** Creates a transition with duration and incoming scene.
	*
	* @param t Duration time, in seconds.
	* @param scene A given scene.
	* @return A autoreleased TransitionSplitCols object.
	*/
	static TransitionExA* create(float t, Scene* scene);

	/** Returns the action that will be performed.
	*
	* @return The action that will be performed.
	*/
	virtual ActionInterval* action();

	//
	// Overrides
	//
	/**
	* @lua NA
	*/
	virtual void onEnter() override;
	virtual void onExit() override;
	virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

CC_CONSTRUCTOR_ACCESS:
	TransitionExA();
	virtual ~TransitionExA();

protected:
	NodeGrid* _outSceneProxy;
private:
	CC_DISALLOW_COPY_AND_ASSIGN(TransitionExA);
};

/** @class TransitionExB
* @brief TransitionExB:
The odd columns goes upwards while the even columns goes downwards.
*/
class TransitionExB : public TransitionScene
{
public:
	/** Creates a transition with duration and incoming scene.
	*
	* @param t Duration time, in seconds.
	* @param scene A given scene.
	* @return A autoreleased TransitionSplitCols object.
	*/
	static TransitionExB* create(float t, Scene* scene);

	/** Returns the action that will be performed.
	*
	* @return The action that will be performed.
	*/
	virtual ActionInterval* action();

	//
	// Overrides
	//
	/**
	* @lua NA
	*/
	virtual void onEnter() override;
	virtual void onExit() override;
	virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

CC_CONSTRUCTOR_ACCESS:
	TransitionExB();
	virtual ~TransitionExB();

protected:
	NodeGrid* _inSceneProxy;
private:
	CC_DISALLOW_COPY_AND_ASSIGN(TransitionExB);
};

#endif