///**********************
///״̬����
///************************


#ifndef stateMachine_h_h_h
#define stateMachine_h_h_h

#include "State.h"
#include <vector>



class StateMachine
{
public:
    
	///���캯��
	StateMachine();
    
	///��������
	virtual ~StateMachine();
    
    
	/**��ʼ��������һ�������������ע�����е�״̬
     *�������������Ҫ�ֶ�ָ����ǰ�״̬��ͬʱ���û״̬��begin����
     */
	virtual void  initState()=0;
    
    
	/**ÿ֡���º���
     *@param time ��һ֡����ǰ֡��ʱ��
     */
	virtual void  update(float time);
    
    
	/**��������״̬
     *@remark ��ɾ������״̬���ڴ� 
     */
	void destroyAllState();
    
    
	/**����ָ������״̬
     *@return ���û�ҵ����ؿ�
     */
	State* findState(StateType type);
    
    
	/**ע��һ���µ�״̬
     *@return ����Ѿ�ע���˷���false
     */
	bool  registerState(State* pState);
    
    
	/**ע��һ��״̬
     *@return  �ɹ������档ʧ�ܷ��ؼ�
     *@remark �������״̬�ڴ档ע����״̬��Ҫ�û��ֹ�ɾ��
     */
	bool unregisterState(StateType type);
    
    
	/**��ȡ״̬������*/
	size_t getStateCount()const {return m_stateCollect.size();}
    
    
	/**��ȡָ��������״ָ̬�� 
     *�޷��ؿ�
     */
	State* getState(unsigned int index) const ;
    
    
	/**���ص�ǰ�״̬*/
	State* getCurrentActive()const {return m_pcurrentState;}
    
	///������Ϸ��ʼ��״̬
	void setBeginState(StateType GS);
    
    
protected:
    
	typedef std::vector<State*>  StateCollect;
    
	
	///��������״̬������
	StateCollect m_stateCollect;
    
    
	//���浱ǰ��״̬����
	State* m_pcurrentState;
    
};


#endif