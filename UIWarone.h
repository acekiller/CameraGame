#include "UIBase.h"
#include "UILLayout.h"


class Widget;
class StaticImage;
class RotateImage;
class EnemyQueue;

class UIWarone :public UILayout
{

public:

	UIWarone();

	~UIWarone();


	/**��ʼ��*/
	virtual void init();

	virtual void update(float time);

	/**����ʱ��
	*@param time ��ʣ������
	*/
	void setTime(int time);


	///ɱ��һ�ӵ���
	void onKillEnemyQueue(EnemyQueue* pEnemyQueue);

	///��������
	void onLostEnemyQueue(EnemyQueue* pEnemyQueue);

	///�����µ���
	void onCrateEnemyQueue(EnemyQueue* pEnemyQueue);

	/**���÷���*/
	void setScore(unsigned int    score);

	/**����ui״̬Ϊ��ʼ*/
	void reset();


protected:


	/**��ť�ص��¼�*/
	virtual void buttonHit(Widget* button);


	void updateEnemyDir();

	

protected:

//	Widget*        m_PauseButton;     ///��ͣ��ť
	//Widget*        m_FirePoint;       ///׼��ͼ��

	StaticImage*        m_HundredTime;     ///����
	StaticImage*        m_TenTime;          ///ʮ��
	StaticImage*        m_DigitTime;        ///��λ����
	

	StaticImage*        m_ScoreImage[5];


	EnemyQueue*          m_pEnemy;
    RotateImage*          m_pRotateImage;//ָ����˵ķ���

};