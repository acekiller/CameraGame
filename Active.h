

/***********************************************
������
****************************************************/

#pragma  once 

class Active
{

public:

	Active(){}

	virtual ~Active(){}

	virtual void  begin(){}

	virtual bool   update(float time){ return true;}

	virtual void  end(){}

protected:


};
typedef  std::vector<Active*> ActitveVector;




/**�������У��Ѷ����������һ�����������������еĶ�������
���У�ֱ�����ж���������ˣ��������������н���*/

class ActiveQueue :public Active
{
public:

	ActiveQueue();

    virtual 	~ActiveQueue();


protected:



	ActitveVector m_ActiveVector;


};











///��ת����
class RotateActive :public Active
{
public:

	RotateActive();

	~RotateActive();



protected:



};