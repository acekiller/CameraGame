/*
 *  ofxiPhoneVideoGrabber.h
*
 */

#pragma once




#if OGRE_PLATFORM == OGRE_PLATFORM_IPHONE




#import <UIKit/UIKit.h>



//*
#if __IPHONE_OS_VERSION_MIN_REQUIRED > __IPHONE_3_2


class ofxiPhoneVideoGrabber;

//#if defined  __arm__



@interface iPhoneVideoGrabber : UIViewController <AVCaptureVideoDataOutputSampleBufferDelegate> 
{

	@public
	
	AVCaptureDeviceInput		*captureInput;	
	AVCaptureSession			*_captureSession;
	CGImageRef currentFrame;	
	
	int width;
	int height;
    int fps;
	
	ofxiPhoneVideoGrabber * grabberPtr;
	
	bool bInitCalled;
}

-(void)initCapture:(int)framerate capWidth:(int)w capHeight:(int)h;

-(void)startCapture;
-(void)stopCapture;
-(void)lockExposureAndFocus;

-(CGImageRef)getCurrentFrame;


@property (nonatomic, retain) AVCaptureSession *captureSession;
@property (nonatomic)ofxiPhoneVideoGrabber * grabberPtr;


@end




class ofxiPhoneVideoGrabber : public Ogre::Singleton<ofxiPhoneVideoGrabber>
{

	public:		
    ofxiPhoneVideoGrabber(int width,int height);
    ~ofxiPhoneVideoGrabber();
		
		void clear();
		void setCaptureRate(int capRate);
	
		void initGrabber(int w, int h);
		void updatePixelsCB( CGImageRef & ref );		
		void draw(float x, float y);
		void draw(float x, float y, float w, float h);
    
         ///�µ�ת�����غ���
       void updatePixels(uint8_t* pImage,int w,int h, int preByterow);
	
		unsigned char * getPixels(){
			return pixels;
		}
		float getWidth() const 
        {
			return m_width;
		}
		float getHeight() const 
        {
			return m_height;
		}
    
    /**ֹͣ��ȡͼ��*/
    void stopCapture();
    
    /**��ʼ��ȡͼ��*/
    void startCapture();
    
    bool isUpdate()const {return m_bUpdateTex;}
    
    bool converImageBufferToPixels(CVImageBufferRef& pBuffer);
	
    ///ÿ֡����
    void update();
    
    /**���ػ�ȡ��ͼ��
     */
    Ogre::TexturePtr getOgreTexture() const ;
    
    
    /**�ѵ�ǰͼ�񱣴浽ָ��Ŀ¼����png��ʽ
       */
    bool  saveTexture(const char* fileName);
    
   /**��ȡͼ��
      */
    bool getOgreTexture(Ogre::TexturePtr pTexture);
    
	protected:
    
    /**��ʼ��ogre��ͼ*/
    void initOgreTexture();
    
    /**����ogre��ͼ*/
    void updateOgreTexture();
    
		
    bool convertCGImageToPixels(CGImageRef & ref, unsigned char * pixels);
    
   
    
protected:
    
    
    int m_width, m_height;
	
    bool m_bUpdateTex;
    
    int fps;
		//ofTexture tex;
    
    unsigned char * pixels;
    iPhoneVideoGrabber * grabber;
    
    ////ogre �ӿ�
    Ogre::TexturePtr m_pTexture;
    
    bool       m_isCapture;
    
    unsigned  char*       m_pTemPixel;
};


//#endif	// (__arm__) compile only for ARM

 
#else   // (> 3.2 SDK) compile for 4.0+

#warning "skipping ofxIphoneVideoGrabber compilation because you need > 3.2 iOS SDK"


#endif
//*/


#endif///platform =iphone