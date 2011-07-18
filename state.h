
/**********************
 ״̬����״̬����
 ***********************/

#pragma once


/**״̬������*/
enum StateType
{
    ST_NONE,

	ST_GAMEPLAY=1,    //��ʼ��Ϸ
	ST_SELECTMODE,    ///ѡ��ģʽ
    ST_CAPTUREFACE,//��������
    
    ST_WAR,///ս��״̬
    
};




class State
{
    
    
protected:
    
	///�����״̬
	StateType m_type;
    
	///��һ֡����Ϸ״̬
	StateType m_NextType;
    
	///�Ƿ���ͣһ��״̬
	bool m_stopState;
    
    
    
public:
    
	State( StateType type)
    :m_type(type),m_NextType(type),m_stopState(false)
	{
      
	}
    
	virtual ~State(){}
    
	
	/**ÿ֡���º���
     *@param time ��һ֡����ǰ֡��ʱ��
     *@return ������֡���Զ���ʻ״̬������뵱ǰ״̬��һ����ʾ��Ҫ����״̬ 
     */
	virtual StateType update(float time)
    {
        return m_NextType;
    }
    
	/**��ʼ״̬��ʼ��*/
	virtual void begin()
    {
        m_NextType = getType();
    }
    
	/**״̬���������ʼ��������*/
	virtual void  end(){}
    
	/**���ص�ǰ״̬������*/
	StateType getType()const
    { 
        return m_type;
    }
    
	///������һ��״̬
	void setNextStateType(StateType stype)
    {
        m_NextType=stype;
    }
    
	///��ͣ��Ϸ״̬
	void stopGameState()
	{
		m_stopState=!m_stopState;
	}
    

    
	
    
};


