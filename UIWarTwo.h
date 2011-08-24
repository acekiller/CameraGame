
/***************************************************
ս��ģʽ2��ui����
*******************************************************/



#pragma  once


#include "UIBase.h"
#include "WarManager.h"


class RotateImage;
class ImageButton;
class StaticImage;
class Widget;
class EnemyQueue;

class UIWarModeTwo :public UIBase
{

public:


	UIWarModeTwo();


	~UIWarModeTwo();


	 void init();


	 /**ÿ֡����*/
	 virtual void update(float time);


	 ///���õ������еķ���
	 void notityEmeny(EnemyQueue* pEnemyQueue){m_pEnemy=pEnemyQueue;}


	 ///����ָ����˵ļ�����
	 void updateEnemyDir();



	 ///ɱ��һ�ӵ���
	 void onKillEnemyQueue(EnemyQueue* pEnemyQueue);

	 ///��������
	 void onLostEnemyQueue(EnemyQueue* pEnemyQueue);

	 ///�����µ���
	 void onCrateEnemyQueue(EnemyQueue* pEnemyQueue);


	 ///����״̬����Ϸ��ʼʱ����
	 void reset();


protected:

	 /**��ť�ص��¼�*/
	 virtual void buttonHit(Widget* button);

	 /**��ʼ����,*/
	 virtual void onBeginTouch(int x,int y);





	  ImageButton* m_PauseButton;  ///��ͣ��ť
	  ImageButton* m_pFireButton;  ///����ť
	  StaticImage* m_FirePoint;    ///�м�׼��
      RotateImage* m_pRotateImage;//ָ����˵ķ���

	  EnemyQueue*  m_pEnemy;

	  typedef std::vector<Widget*> WidgetCollect;
	  WidgetCollect  m_LifeCollect;


};