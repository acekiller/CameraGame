
#pragma once



/************************************
��Ϸģʽ����
*************************************/

class GameState;


class  GameMode
{
public:

	GameMode(GameState* pGameState)
	:m_end(false),m_pGameState(pGameState){}

	virtual ~GameMode(){}

	
	/**��ʼ��Ϸ*/
	virtual void start()=0;

	/**��Ϸ����*/
    virtual	void end()=0;

	/**ÿ֡����*/
	virtual void update(float time)=0;


	/**��������¼�*/
	virtual  void beginTouch(int x,int y)=0;

	/**����뿪�¼�*/
	virtual void  endTouch(int x,int y)=0;

	/**����ƶ��¼�*/
	virtual void  moveTouch(int x,int y){}


	/**�ж���Ϸ�Ƿ����*/
	bool    isEnd()const{return m_end;}



protected:

	


	GameState*       m_pGameState;

	bool             m_end;////trueΪ��Ϸ����



};







/***************************************************
��Ϸģʽ2
****************************************************/
class GameModeTwo :public GameMode
{


public:

	GameModeTwo(GameState* pGameState);


	virtual ~GameModeTwo();


	/**��ʼ��Ϸ*/
	virtual void start();

	/**��Ϸ����*/
	virtual	void end();

	/**ÿ֡����*/
	virtual void update(float time);


	/**��������¼�*/
	virtual  void beginTouch(int x,int y);

	/**����뿪�¼�*/
	virtual void  endTouch(int x,int y);

	/**����ƶ��¼�*/
	virtual void  moveTouch(int x,int y);


protected:

	///��ʼ��ui��Ϸ��ʼ
	void initUI();

	///����ui
	void destroyUI();





};