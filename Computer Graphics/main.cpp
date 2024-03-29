#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include<cstdio>
#include <cmath>
#include <vector>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<Mmsystem.h>
#include <string>
using std::string;
#define STROKEFONT  GLUT_STROKE_ROMAN
#define PI 3.1415926535897932384626433832795
string path = "E:\\Desktop\\OneDrive\\Documents\\Docs Files\\ab\\resources\\";
//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//---------------akash-----------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
void drawStaticStars(int );
bool text1=true, text2=false, text3=false, text4=false;
bool isShuvo=true;
bool isAbha=false;
bool isSajin=false;
bool isAkash=false;
int DisplaySizeX = 50;
int DisplaySizeY = 30;
GLfloat BackgroundPosition = 0;
bool rightMouseClicked=false;
GLfloat BackgroundMoveSpeed = 0.185f;
GLfloat FinalDestination =0;
bool isProcessing = false;
GLfloat RocketPosition = 0;
GLfloat RocketMoveSpeed = 0.15f;
GLfloat RocketAngle = 0;
GLfloat RocketSpinSpeed = 0.35f;
GLfloat RocketSize = 1;
GLfloat RocketSizeChanger = 0.001;
bool isRocketinGalaxy = false;
bool canRocketControl = false;
GLfloat RocketPositionY = 0;
GLfloat SCPosition = 0;
GLfloat SCMoveSpeed = 0.15f;
GLfloat SCAngle = 0;
GLfloat SCSpinSpeed = 0.35f;
GLfloat SCSize = 1;
GLfloat SCSizeChanger = 0.001;
bool isSCinGalaxy = false;
GLfloat SCPositionY = 0;
GLfloat FTPosition = 0;
GLfloat FTMoveSpeed = 0.15f;
GLfloat FTAngle = 0;
GLfloat FTSpinSpeed = 0.35f;
GLfloat FTSize = 1;
GLfloat FTSizeChanger = 0.001;
bool isFTinGalaxy = false;
bool canFTControl = false;
GLfloat FTPositionY = 0;
GLfloat BigMeteorPosition = 110;
GLfloat BigMeteorMoveSpeed = 0.35f;
GLfloat SmallMeteorPosition = 110;
GLfloat SmallMeteorMoveSpeed = 0.085f;
bool rocketInGalaxy = false;
bool fuelTankDetached = false;
bool shuttleCockDetached=false;
int detachmentTime = 8000;
float _scale=0.0f;
bool IsFire=false;
GLfloat StarsPosition = 0;
GLfloat StarsMoveSpeed = 0.05f;
GLfloat StarsAngle = 0;
bool AkashScene=false;
bool dayBackground = false;
float _move = 0.0f;
float CloudPositionX = -30;
float CloudMoveSpeed = 0.0001;
float FlyingObjectPositionX = -25.0f;
float FlyingObjectMoveSpeed = 0.008f;
float FlyingObject1PositionX = -15.0;
float FlyingObject1PositionY = -9.0;
float FlyingObject1MoveSpeed = 0.01;
float FlyingObject2PositionX = -10.0;
float FlyingObject2PositionY = 8.0;
float FlyingObject2MoveSpeed = 0.03;
bool liftUpObject2 = false;
bool liftUp = false;

void E_DrawTextStroke(float ,float ,float ,float ,float ,char* , void*);
void ApplyTexture(float , float ,float , float ,float , float ,float, float, GLuint );
std::string animatedText;
int currentLength = 0;
double textPosX, textPosY;
GLfloat textColor[3];

void I_Timer(int value) {
    if (currentLength < animatedText.length()) {
        currentLength++;
        glutPostRedisplay();
    }
}
void I_AnimatedText(const std::string& text, double posX, double posY) {
    animatedText = text;
    textPosX = posX;
    textPosY = posY;
    textColor[0] = 1;
    textColor[1] = 1;
    textColor[2] =1;
}

void I_AnimatedTextAdder(const std::string& text, double posX, double posY){
    // Set text properties
    glColor3fv(textColor);
    glRasterPos2d(textPosX, textPosY);

    // Display characters up to the current length
    for (int i = 0; i < currentLength; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, animatedText[i]);
    }
    I_AnimatedText(text,posX,posY);
}

//AK001
void A_Circle(float radius,int steps,float X,float Y,int r,int g=0,int b=0,int t=0){

    float Radius = radius;
    int Steps = steps;
    float Pi=3.1416f;
    glPushMatrix();
    glTranslatef(X, Y, 0);
    glBegin(GL_POLYGON);
     glColor3ub(r,g,b);
    for(int i=0;i<Steps;i++)
        {
            float A=(i*2*Pi)/Steps;
            float x = Radius * cos(A);
            float y = Radius * sin(A);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
}

//AK002
void A_SunMoon(float r, float g, float b, float x, float y) {
    glColor3f(r, g, b);
    glPushMatrix();
    glTranslatef(x, y, 1.0f);
    glutSolidSphere(2.0f, 80, 80);
    glPopMatrix();
    glColor3f(r + 0.2f, g + 0.2f, b + 0.2f);
    glPushMatrix();
    glTranslatef(x - 0.2f, y, 1.0f);
    glutSolidSphere(1.8f, 80, 80);
    glPopMatrix();
}

//AK003
void A_Cloud(){
glPushMatrix();
glTranslatef(5+CloudPositionX,15,0);
A_Circle(2,30,2.5,-1,255,255,255);
A_Circle(2,30,-1,-2,255,255,255);
A_Circle(2,30,1,0,255,255,255);
A_Circle(2.3,35,-2.5,1,255,255,255);
glPopMatrix();

glPushMatrix();
glTranslatef(-20+CloudPositionX,9,0);
glScalef(1.0,1.0,0);
A_Circle(1.5,30,-2.2,-1,255,255,255);
A_Circle(1.5,30,-1.2,-1.2,255,255,255);
A_Circle(1.5,30,1.2,-1.6,255,255,255);
A_Circle(1.8,35,2.2,-0.7,255,255,255);
glPopMatrix();
glPushMatrix();
glTranslatef(-15+CloudPositionX,18,0);
glScalef(0.50,0.50,0);
A_Circle(1.5,30,-2.2,-1,255,255,255);
A_Circle(1.5,30,-1.2,-1.2,255,255,255);
A_Circle(1.5,30,1.2,-1.6,255,255,255);
A_Circle(1.8,35,2.2,-0.7,255,255,255);
glPopMatrix();

glPushMatrix();
glTranslatef(20+CloudPositionX,18,0);
A_Circle(1.2,30,0.8,-1,255,255,255);
A_Circle(1.2,30,-1,-1,255,255,255);
A_Circle(1.2,30,1,0,255,255,255);
A_Circle(0.8,35,-0.50,0.6,255,255,255);
glPopMatrix();

glPushMatrix();
glTranslatef(15+CloudPositionX,8,0);
A_Circle(1.2,30,0.8,-1,255,255,255);
A_Circle(1.2,30,-1,-1,255,255,255);
A_Circle(1.2,30,1,0,255,255,255);
A_Circle(0.8,35,-0.50,0.6,255,255,255);
glPopMatrix();

}

//AK004
void A_GroundLine() {

    // (0.447, 0.486, 0.50) grey color
    glColor3f(0.039, 0.267, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(-25.0f, -20.0f);
    glVertex2f(-25,-18.4086886256259f);
    glVertex2f( 25,-18.4086886256259f);
    glVertex2f(25.0f, -20.0f);
    glEnd();

}

//AK005
void A_GradientEffect(float r, float g, float b,float r1, float g1, float b1){

    glBegin(GL_POLYGON);
    glColor4ub(r,g,b,80);
    glVertex2f(-25, 20);
    glVertex2f( 25, 20);
    glColor4ub(r1,g1,b1, 80);
    glVertex2f(25, -20);
    glVertex2f(-25, -20);
    glEnd();


}

//AK006
void A_AdvancedBuildingtype1(float r, float g, float b ) {
    glColor3f(r,g,b);
    {
    glBegin(GL_POLYGON);
    glVertex2f(-23.8366801660355, -18.4086886256259f);
    glVertex2f(-23.8366801660355, -11.0308746246419);
    glVertex2f(-23.1059317423443, -11.0360385862192);
    glVertex2f(-23.1097691006661, -12.3462876435269);
    glVertex2f(-23.1018817308611, -13.0324888165645);
    glVertex2f(-23.0703322516409, -14.199819547709);
    glVertex2f(-23.0147225431851, -15.377807492037);
    glVertex2f(-22.9127139790369, -16.6964644311342);
    glVertex2f(-22.8078770476077, -17.4303229511385);
    glVertex2f(-22.7515836476777, -17.6368899131174);
    glVertex2f(-22.7171590961812, -17.7562283583092);
    glVertex2f(-22.6666697539835, -17.8434372221033);
    glVertex2f(-22.6276552622861, -17.8709768633014);
    glVertex2f(-22.5817558602893, -17.8847466839005);
    glVertex2f(-22.4696966634496, -18.0019204850058);
    glVertex2f(-22.3740441145095, -18.1069507348224);
    glVertex2f(-22.1197372614469, -18.4086886256259f);
    glEnd();

    //left mid
    glBegin(GL_POLYGON);
    glVertex2f(-23.8366801660355, -11.1308746246419);
    glVertex2f(-23.1176504689531, -11.1255624889911);
    glVertex2f(-23.1034086228567, -10.3624447714398);
    glVertex2f(-23.0462539225096, -8.8249833321042);
    glVertex2f(-22.9367485362184, -7.426974677187);
    glVertex2f(-22.8597744179278, -6.61447009523);
    glVertex2f(-22.765694940017, -6.1440727056759);
    glVertex2f(-22.6913376322446, -5.9231592144503);
    glVertex2f(-22.6152626717182, -5.7343267476599);
    glVertex2f(-23.8366801660355, -5.7343267476599);
    glEnd();

    //left upper
    glBegin(GL_POLYGON);
    glVertex2f(-22.6152626717182, -5.7343267476599);
    glVertex2f(-22.5, -6);
    glVertex2f(-22.4527914134822, -6.1821907210927);
    glVertex2f(-22.3918646916437, -6.378510158128);
    glVertex2f(-22.3715557843642, -6.5748295951632);
    glVertex2f(-21.2626854635757, -6.5748295951632);
    glVertex2f(-21.2626854635757, -5.7343267476599);
    glEnd();

    //right upper
    glBegin(GL_POLYGON);
    glVertex2f(-22.3700069179971, -6.4157801963479);
    glVertex2f(-22.3027361895581, -6.4987058813088);
    glVertex2f(-22.2613388182110, -7.4592516375455);
    glVertex2f(-22.2302907897006, -8.0025921364764);
    glVertex2f(-22.2147667754454, -8.2871990644879);
    glVertex2f(-21.2626854635757, -8.2768497216511);
    glVertex2f(-21.2696780974601, -6.5947014219356);
    glEnd();

    //right mid
    glBegin(GL_POLYGON);
    glVertex2f(-22.2147667754454, -8.2871990644879);
    glVertex2f(-21.2626854635757, -8.2768497216511);
    glVertex2f(-21.2626854635757, -11.0594321662571);
    glVertex2f(-22.1165594219244, -11.0594321662571);
    glVertex2f(-22.1104977524086, -10.3367799724112);
    glVertex2f(-22.1214611830631, -9.5822085800609);
    glVertex2f(-22.138662655842, -8.8884158446446);
    glEnd();

//right lower
    glBegin(GL_POLYGON);

    glVertex2f(-21.274084164208, -11.0594321662571);
    glVertex2f(-22.1165594219244, -11.0594321662571);
    glVertex2f(-22.1111860604702, -11.3607038991406);
    glVertex2f(-22.1111860604702, -11.8991074928019);
    glVertex2f(-22.1170474355386, -12.6376473735045);
    glVertex2f(-22.1277101428994, -13.3627114740443);
    glVertex2f(-22.1490355576212, -14.2477161849972);
    glVertex2f(-22.1916863870647, -15.3779631652503);
    glVertex2f(-22.2671009162087, -16.4255040600254);
    glVertex2f(-22.3682650625171, -17.1842351573382);
    glVertex2f(-22.5561413342326, -17.834576097892);
    glVertex2f(-22.5561413342326, -18.4086886256259f);
    glVertex2f(-21.2626854635757, -18.4086886256259f);
    glEnd();

    //top
    glBegin(GL_POLYGON);
    glVertex2f(-23.8050939379767, -5.8810133408323);
    glVertex2f(-23.811210820942, -5.3691805259353);
    glVertex2f(-23.772277953534, -5.2650671268525);
    glVertex2f(-23.7038530279754, -5.18637846246);
    glVertex2f(-23.6234537404439, -5.1128216674844);
    glVertex2f(-23.5447650760514, -5.0563711038984);
    glVertex2f(-23.460944542242, -5.0221586411191);
    glVertex2f(-23.3685708927378, -5.0050524097294);
    glVertex2f(-21.6281386298457, -4.9883452359542);
    glVertex2f(-21.5381489217903, -5.0250585293572);
    glVertex2f(-21.4896501327514, -5.0561474966898);
    glVertex2f(-21.4274721980861, -5.1133511965819);
    glVertex2f(-21.3603200286476, -5.1842340421004);
    glVertex2f(-21.3143083569952, -5.2277585963661);
    glVertex2f(-21.2819758309693, -5.2663089158586);
    glVertex2f(-21.24839974625, -5.3172948222841);
    glVertex2f(-21.232233483237, -5.3732549634829);
    glVertex2f(-21.2301287592502, -5.8810133408323);

    glEnd();
    }
}

//AK007
void A_AdvancedBuildingtype2(float r, float g, float b ) {

    glColor3f(r, g, b);
    {
    glBegin(GL_POLYGON);
    glVertex2f(-18.3175959863024, -18.4086886256259f);
glVertex2f(-18.3175954070891, -11.9629076659314);
glVertex2f(-18.2837757735569, -11.868790664992);
glVertex2f(-18.2342792291221, -11.7718599321405);
glVertex2f(-18.1609527878346, -11.6842499968598);
glVertex2f(-18.0849207117175, -11.6173417698768);
glVertex2f(-18.0050870317947, -11.5679209204007);
glVertex2f(-17.9457820124234, -11.5435906560433);
glVertex2f(-17.3768937368074, -11.5403497586197);
glVertex2f(-17.2936704378322, -11.5704823323866);
glVertex2f(-17.2147517922522, -11.6192684041997);
glVertex2f(-17.1401378000675, -11.6867079740589);
glVertex2f(-17.0726982302083, -11.751277774988);
glVertex2f(-17.0268357962498, -11.8243558654157);
glVertex2f(-16.9703361945867, -11.9);
glVertex2f(-16.9703361945867, -18.4086886256259f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-16.2971284964821, -18.4086886256259f);
glVertex2f(-16.2971284964821, -13.1755062249858);
glVertex2f(-15.9990311308015, -12.9579565107271);
glVertex2f(-15.9108353006967, -12.9079788736677);
glVertex2f(-15.8196996095883, -12.8844599856398);
glVertex2f(-15.722684196473, -12.8785802636328);
glVertex2f(-15.6462478103821, -12.8932795686502);
glVertex2f(-15.5580519802773, -12.9226781786852);
glVertex2f(-15.5051344822144, -12.9461970667132);
glVertex2f(-15.1699903278159, -13.1372880319403);
glVertex2f(-15.1699903278159, -18.4086886256259f);
    glEnd();}
}

//AK008
void A_AdvancedBuildingtype3(float r, float g, float b ) {//polygon building
    glColor3f(r, g, b);
    {
    glBegin(GL_POLYGON);
    glVertex2f(-13.9848438349274, -18.4086886256259f);
glVertex2f(-13.9928560842054, -9.0649353875661);
glVertex2f(-13.9842041141894, -8.9809142971093);
glVertex2f(-13.95, -8.9);
glVertex2f(-13.902587967906, -8.8312846955898);
glVertex2f(-13.8286233353367, -8.7675220813059);
glVertex2f(-13.7657108892433, -8.7156618216883);
glVertex2f(-13.6857950793408, -8.6765540849275);
glVertex2f(-13.6, -8.65);
glVertex2f(-13.5205195275488, -8.6259440260515);
glVertex2f(-13.4276527477182, -8.6047173335187);
glVertex2f(-13.3268259581879, -8.6033906652355);
glVertex2f(-13.2595995, -8.6033906652355);
glVertex2f(-12.7165585478726, -8.6013906652355);
glVertex2f(-12.7217638417906, -18.4086886256259f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-12.7217638417906, -18.4086886256259f);
glVertex2f(-12.7217638417906, -7.7679887650682);
glVertex2f(-12.7181700162139, -7.6535285716246);
glVertex2f(-12.6663589808658, -7.5538919651859);
glVertex2f(-12.6095661151957, -7.4831499746143);
glVertex2f(-12.5288604639803, -7.4084225197853);
glVertex2f(-12.4463688197648, -7.3523117925147);
glVertex2f(-12.3594940991945, -7.3108488576971);
glVertex2f(-12.2691917572439, -7.2948160101866);
glVertex2f(-11.3068531471242, -7.284566469737);
glVertex2f(-11.3068531471242, -18.4086886256259f);
    glEnd();

    glBegin(GL_POLYGON);
glVertex2f(-11.3068531471242, -18.4086886256259f);
glVertex2f(-11.3068531471242, -6.0768994202993);
glVertex2f(-11.3451638449464, -5.8818481546883);
glVertex2f(-11.3400454082887, -5.8084838959283);
glVertex2f(-11.3093347883426, -5.7351196371683);
glVertex2f(-11.2666811495287, -5.6515185050929);
glVertex2f(-11.2120844918468, -5.5849788285431);
glVertex2f(-11.1677247074803, -5.538912898624);
glVertex2f(-11.1199526320086, -5.5030838420203);
glVertex2f(-11.0738867020895, -5.480903949837);
glVertex2f(-11.01417160775, -5.4553117665486);
glVertex2f(-10.9322766212272, -5.4450748932333);
glVertex2f(-10.7155961360522, -5.4399564565756);
glVertex2f(-8.7854051738406, -5.4298945171526);
glVertex2f(-8.6639729295437, -5.4298945171526);
glVertex2f(-8.5689389992244, -5.4800513137101);
glVertex2f(-8.4950237200872, -5.5302081102675);
glVertex2f(-8.4, -5.6);
glVertex2f(-8.3428714361394, -5.6901549759942);
glVertex2f(-8.3018114126756, -5.7624988268588);
glVertex2f(-8.2783485421249, -5.8915446148877);
glVertex2f(-8.2724828244873, -6.102710449844);
glVertex2f(-8.2724828244873, -18.4086886256259f);
    glEnd();}
}

//AK009
void A_AdvancedBuildingtype4(float r, float g, float b ) {//polygon building
    glColor3f(r, g, b);
    {
    glBegin(GL_POLYGON);
    glVertex2f(-5.1646131129979f, -18.4086886256259f);
    glVertex2f(-5.1556356956362f, -15.528171769908f);
    glVertex2f(-5.0705243118221f, -15.425018519882f);
    glVertex2f(-4.9533809466809f, -15.321862422165f);
    glVertex2f(-4.8397343984095f, -15.244932451029f);
    glVertex2f(-4.7400751176178f, -15.199473831725f);
    glVertex2f(-4.6474094705657f, -15.181989747371f);
    glVertex2f(-4.5372597391643f, -15.181989747771f);
    glVertex2f(-4.4290594551811f, -15.207422250127f);
    glVertex2f(-4.3272739707688f, -15.254856267236f);
    glVertex2f(-4.2324059464622f, -15.326007287076f);
    glVertex2f(-4.1552622226624f, -15.436459575554f);
    glVertex2f(-4.0871392842427f, -15.460403648436f);
    glVertex2f(-4.0277115190344f, -15.534564846631f);
    glVertex2f(-4.0347369531555f, -18.4086886256259f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-7.2014480211429, -18.4086886256259f);
    glVertex2f(-7.2014480211429, -14.2356557169869);
    glVertex2f(-7.1836661759573, -14.1697761257276);
    glVertex2f(-7.1290568512547, -14.0735422916418);
    glVertex2f(-7.0403946368928, -13.965624813012);
    glVertex2f(-6.9831326929976, -13.905520320233);
    glVertex2f(-6.9171248259993, -13.8523295147878);
    glVertex2f(-6.8671382859424, -13.826054538604);
    glVertex2f(-6.7975938873943, -13.8119796807043);
    glVertex2f(-6.2333081995718, -13.8125793736862);
    glVertex2f(-6.1628137211969, -13.834807362363);
    glVertex2f(-6.0887857348065, -13.8874411936815);
    glVertex2f(-6.0159282047808, -13.9533087483081);
    glVertex2f(-5.9572394050024, -14.0264687589908);
    glVertex2f(-5.9194534654191, -14.0972169011894);
    glVertex2f(-5.8864912628038, -14.1776125173243);
    glVertex2f(-5.8748846018572, -14.2710303145881);
    glVertex2f(-5.8748846018572, -18.4086886256259f);
    glEnd();}
}

//AK010
void A_AdvancedBuildingtype5(float r, float g, float b ) {//T hollow building
    glColor3f(r, g, b);
    {
    glBegin(GL_POLYGON);
    glVertex2f(-2.8782581318202, -18.4086886256259f);
    glVertex2f(-2.8782581318202, -15.3050898540957);
    glVertex2f(0.4884925882673, -15.3088192945234);
    glVertex2f(0.4884925882673, -18.4291955066478);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-2.8782581318202, -15.3050898540957);
    glVertex2f(-2.2833299821907, -15.3050898540957);
    glVertex2f(-2.2772040129936, -14.0021830533531);
    glVertex2f(-2.8782581318202, -14.0021830533531);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-2.8782581318202, -14.0021830533531);
    glVertex2f(-2.8782581318202, -11.2913354042453);
    glVertex2f(-2.8263675971542, -11.1708304068077);
    glVertex2f(-2.7478992267297, -11.0755473855779);
    glVertex2f(-2.6329991128938, -10.9774619225472);
    glVertex2f(-2.5237038826596, -10.915808202928);
    glVertex2f(-2.4172110942263, -10.8765740177157);
    glVertex2f(-1.191508995675, -10.8677611526604);
    glVertex2f(-1.0768001529825, -10.9215309226725);
    glVertex2f(-0.9866666149268, -10.9830344970382);
    glVertex2f(-0.9180081765661, -11.0499764744399);
    glVertex2f(-0.8562155820415, -11.1306501395137);
    glVertex2f(-0.815197921265, -11.2139440460013);
    glVertex2f(-0.7806898507624, -11.283609344299);
    glVertex2f(-0.774350114851, -12.6587484531491);
    glVertex2f(-0.774350114851, -14.0021830533531);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.774350114851, -12.6587484531491);
    glVertex2f(-0.774350114851, -14.0021830533531);
    glVertex2f(0.4657192368714, -14.0021830533531);
    glVertex2f(0.4657192368714, -12.6587484531491);
    glEnd();

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(0.4657192368714, -14.0021830533531);
    glVertex2f(-0.2214574497065, -14.0021830533531);
    glVertex2f(-0.2214574497065, -8.1583195189412);
    glVertex2f(-0.1983216631687, -8.0673187585591);
    glVertex2f(-0.1535924758622, -7.9747756124078);
    glVertex2f(-0.0872698877872, -7.9007410954867);
    glVertex2f(-0.0024386704818, -7.8328761216425);
    glVertex2f(0.0823925468236, -7.7866045485668);
    glVertex2f(0.1703085356673, -7.7572992189522);
    glVertex2f(0.2505125956651, -7.7465025185679);
    glVertex2f(0.4657192368714, -7.7434177470295);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.4510227456596, -7.7434177470295);
    glVertex2f(0.4510227456596, -8.1071241078844);
    glVertex2f(2.1071376881817, -8.1071241078844);
    glVertex2f(2.1071376881817, -7.7434177470295);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(2.1270312476645, -18.4291955066478);
    glVertex2f(2.1270312476645, -17.8761284716938);
    glVertex2f(2.1255341775349, -7.7434177470295);
    glVertex2f(2.1071376881817, -7.7434177470295);
    glVertex2f(2.4607107094718, -7.7604996632366);
    glVertex2f(2.5391236353067, -7.7885757458186);
    glVertex2f(2.5944312315729, -7.8300564430182);
    glVertex2f(2.6428253783058, -7.8749938649845);
    glVertex2f(2.6880014200832, -7.9317006183409);
    glVertex2f(2.7271025911523, -7.9775433706289);
    glVertex2f(2.75137228354, -8.0233861229168);
    glVertex2f(2.7769902921715, -8.0705771914485);
    glVertex2f(2.7944389218203, -8.1264595826919);
    glVertex2f(2.8, -8.2);
    glVertex2f(2.8014489138776, -8.3269453555315);
    glVertex2f(2.8014489138776, -18.4086886256259f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(2.8, -18.4086886256259f);
    glVertex2f(2.8, -12.8413240457357);
    glVertex2f(2.9, -12.9);
    glVertex2f(2.9487238397789, -12.9715676964141);
    glVertex2f(2.9778572879569, -13.038403253999);
    glVertex2f(3.0052770038892, -13.1326585275163);
    glVertex2f(3.0155593973638, -13.2132039430674);
    glVertex2f(3.0155593973638, -13.3228828067966);
    glVertex2f(3.0155593973638, -18.4086886256259f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(3.0, -18.4086886256259f);
    glVertex2f(3.0, -16.9297551408614);
    glVertex2f(-2.867579928716, -16.9297551408614);
    glVertex2f(-2.867579928716, -18.4086886256259f);
    glEnd();
    }
}

//AK011
void A_AdvancedBuildingtype6(float r, float g, float b ) {
glColor3f(r, g, b);
{
    glBegin(GL_POLYGON);
    glVertex2f(4.1694153046841, -18.4086886256259f);
glVertex2f(4.1694153046841, -13.0596694595927);
glVertex2f(4.1810829332742, -12.9988575067843);
glVertex2f(4.2348047940464, -12.9211674312061);
glVertex2f(4.3090141848365, -12.8468988241207);
glVertex2f(4.3981368962776, -12.776242980816);
glVertex2f(4.4976974027523, -12.716024932545);
glVertex2f(4.5924404653653, -12.6750766597208);
glVertex2f(4.6992271376326, -12.6606243281357);
glVertex2f(4.8458093354956, -12.6606243281357);
glVertex2f(4.9518522977728, -12.6939602238658);
glVertex2f(5.0194834578045, -12.7352903772185);
glVertex2f(5.1, -12.8);
glVertex2f(5.1802146012477, -12.8771845750587);
glVertex2f(5.2399109423522, -12.9482032884293);
glVertex2f(5.2950178134891, -13.0596694595927);
glVertex2f(5.2950178134891, -18.4086886256259f);
    glEnd();

glBegin(GL_POLYGON);
glVertex2f(5.9948874788396, -18.4086886256259f);
glVertex2f(5.9948874788396, -13.1);
glVertex2f(6.0259824809314, -13.0111042048964);
glVertex2f(6.0754346220502, -12.9105515179548);
glVertex2f(6.16280007136,   -12.8001084027896);
glVertex2f(6.246868711262,  -12.7325238099273);
glVertex2f(6.3375309699797, -12.6715328358808);
glVertex2f(6.3985219440262, -12.6550487888412);
glVertex2f(6.8818224295101, -12.6540826384413);
glVertex2f(6.988253896727,  -12.6595866307806);
glVertex2f(7.0686020309906, -12.6873994464872);
glVertex2f(7.158221103823,  -12.7605368507527);
glVertex2f(7.24681007237,   -12.8480957150143);
glVertex2f(7.3040715209441, -12.9330635557127);
glVertex2f(7.3572531220333, -13.0267174179596);
glVertex2f(7.373545506412,  -13.0907232137333);
glVertex2f(7.373545506412, -18.4086886256259f);
    glEnd();
}
}

//AK012
void A_AdvancedBuildingtype7(float r, float g, float b ) {

    glColor3f(r, g, b);
    {
    glBegin(GL_POLYGON);
    glVertex2f(7.8164322223154, -18.4086886256259f);
glVertex2f(7.816467506431, -5.9603692689819);
glVertex2f(7.8228335958396, -5.8483393212472);
glVertex2f(7.8868507088309, -5.7363093735124);
glVertex2f(7.9604703887709, -5.6466854153246);
glVertex2f(8.0437144753577, -5.5853996044322);
glVertex2f(8.1333945936844, -5.5434712374222);
glVertex2f(8.2370508343478, -5.5260010845015);
glVertex2f(8.3442011055954, -5.515518992749);
glVertex2f(10.3530093718919, -5.5058512278143);
glVertex2f(10.4635839837158, -5.5201189196625);
glVertex2f(10.5456232118431, -5.5629219952072);
glVertex2f(10.6129822823521, -5.6123453499234);
glVertex2f(10.6692582789773, -5.6662765133559);
glVertex2f(10.7231894424098, -5.7366215091374);
glVertex2f(10.7665688564751, -5.8057940883226);
glVertex2f(10.7993965211731, -5.8784839172968);
glVertex2f(10.8209730593279, -5.9661090181988);
glVertex2f(10.8499523829898, -12.6603825849649);
glVertex2f(11.3993232184419, -12.6603825849649);
glVertex2f(11.3993232184419, -18.4086886256259f);
    glEnd();

    glBegin(GL_POLYGON);
glVertex2f(11.3993232184419, -18.4086886256259f);
glVertex2f(11.3993232184419, -9.1262825394146);
glVertex2f(11.4376515262861, -9.0432228496298);
glVertex2f(11.4419294422128, -8.9811930686931);
glVertex2f(11.4649549407618, -8.9135579267706);
glVertex2f(11.5080771827642, -8.855377124069);
glVertex2f(11.5630051459712, -8.7979045730374);
glVertex2f(11.6139073220779, -8.7530416381637);
glVertex2f(11.6829272218835, -8.7073159545425);
glVertex2f(11.7484961266989, -8.6753942508823);
glVertex2f(11.8295766947511, -8.6479691062461);
glVertex2f(13.0371453278048, -8.640973365269);
glVertex2f(13.1165322417905, -8.6513281801367);
glVertex2f(13.1945474379136, -8.681761923827);
glVertex2f(13.2670650918043, -8.7395658508414);
glVertex2f(13.3353788237303, -8.799471738838);
glVertex2f(13.401590594674, -8.8751423342022);
glVertex2f(13.4478337362854, -8.9392521441635);
glVertex2f(13.4813055559022, -9.0206499104178);
glVertex2f(13.4813055559022, -18.4086886256259f);
glEnd();
    }
}

//AK013
void A_AdvancedBuildingtype8(float r, float g, float b, float r1, float g1, float b1 ) {
    glColor3f(r, g, b);
    {
    glBegin(GL_POLYGON);
    glVertex2f(20.7239316233255, -18.4086886256259f);
glVertex2f(20.7199732529645, -5.4736110381771);
glVertex2f(20.7486602483024, -5.3744737736111);
glVertex2f(20.7880178117465, -5.2957586467229);
glVertex2f(20.8513321529392, -5.2196103174506);
glVertex2f(20.9368920734699, -5.1494511826155);
glVertex2f(21.0369971804907, -5.0964040318865);
glVertex2f(21.1311130930744, -5.0621800636742);
glVertex2f(21.2329293985059, -5.0527684724158);
glVertex2f(22.8747959319256, -5.0467395454184);
glVertex2f(22.9803447077876, -5.0476191185506);
glVertex2f(23.0665772017389, -5.093620763508);
glVertex2f(23.1211231710203, -5.1419329077286);
glVertex2f(23.1834614216275, -5.1995957895403);
glVertex2f(23.2348904783785, -5.265050952678);
glVertex2f(23.2738518850081, -5.3445322222022);
glVertex2f(23.3114958734118, -5.4251102040751);
glVertex2f(23.3379587859689, -5.505277262704);
glVertex2f(23.3550818470353, -5.5916708889934);
glVertex2f(23.3607075303735, -18.4086886256259f);
    glEnd();


    glColor3f(r1,g1,b1);
    glPushMatrix();
    glTranslatef(22.0f, -7.5f, 1.f);
    glScaled(0.6,1.6,0);
    glutSolidSphere(1.0f, 80, 80);
    glPopMatrix();
    }
}

//AK014
void A_AdvancedBuildingtype9(float r, float g, float b ) { //translated buildings
    glPushMatrix();
	glTranslated(16.4,5.0,0);
	glScaled(-1.0,1.3,0);
    A_AdvancedBuildingtype5(0.38, 0.412, 0.431);
    glPopMatrix();

    glPushMatrix();
	glTranslated(17,5.0,0);
	glScaled(-1.0,1.3,0);
    A_AdvancedBuildingtype8(0.38, 0.412, 0.431, 0.196, 0.318, 0.553);
    glPopMatrix();

    glPushMatrix();
	glTranslated(15,-1.0,0);
	glScaled(-1.0,0.95,0);
    A_AdvancedBuildingtype7(0.38, 0.412, 0.431);
    glPopMatrix();

    glPushMatrix();
	glTranslated(-38,-2.0,0);
	glScaled(-1.0,0.9,0);
    A_AdvancedBuildingtype1(0.38, 0.412, 0.431);
    glPopMatrix();

    glPushMatrix();
	glTranslated(-26.5,0.0,0);
	glScaled(-1.0,1.0,0);
    A_AdvancedBuildingtype4(0.38, 0.412, 0.431);
    glPopMatrix();

    glPushMatrix();
	glTranslated(-37.5,0.0,0);
	glScaled(-1.0,1.0,0);
    A_AdvancedBuildingtype3(0.38, 0.412, 0.431);
    glPopMatrix();

    glPushMatrix();
	glTranslated(-0.5,0.0,0);
	glScaled(-1.0,1.0,0);
    A_AdvancedBuildingtype2(r,g,b);
    glPopMatrix();



}

//AK015
void A_Details1(float r, float g, float b ){
    glColor3f(r,g,b); //light details
    {
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(-23.8366801660355, -18.4086886256259);
    glVertex2f(-23.8366801660355, -5.4248099440519);
    glVertex2f(-23.8366801660355, -5.4248099440519);
    glVertex2f(-23.4, -5.0);
    glVertex2f(-21.2450484141595, -18.4086886256259);
    glVertex2f(-21.2450484141595, -5.3822170631674);
    glVertex2f(-21.2285004795586, -5.3822170631674);
    glVertex2f(-21.6, -5.0);
    glVertex2f(-22.2833700035404, -4.9873461183614);
    glVertex2f(-22.2833700035404, -5.3878580766646);
    glVertex2f(-22.5823437188935, -4.9873461183614);
    glVertex2f(-22.5823437188935, -5.3878580766646);
    glVertex2f(-22.8361893262688, -4.9873461183614);
    glVertex2f(-22.8361893262688, -5.3878580766646);
    glVertex2f(-18.0257785443544, -12.2410712097409);
    glVertex2f(-18.0257785443544, -12.5987142314524);
    glVertex2f(-18.0257785443544, -13.0264833358524);
    glVertex2f(-18.0257785443544, -13.5957668751178);
    glVertex2f(-17.422694233233, -12.2410712097409);
    glVertex2f(-17.422694233233, -12.5987142314524);
    glVertex2f(-17.422694233233, -13.0264833358524);
    glVertex2f(-17.422694233233, -13.5957668751178);
    glVertex2f(-17.8343343386147, -12.2410712097409);
    glVertex2f(-17.8343343386147, -12.4505658691646);
    glVertex2f(-17.618346003934, -12.2410712097409);
    glVertex2f(-17.618346003934, -12.4505658691646);
    glVertex2f(-17.8343343386147, -12.7128374184196);
    glVertex2f(-17.8343343386147, -13.2759498624085);
    glVertex2f(-17.6337737421255, -12.7128374184196);
    glVertex2f(-17.6337737421255, -13.2759498624085);
    glVertex2f(-18.2430104643969, -16.5717609446307);
    glVertex2f(-17.5870557770155, -16.5717609446307);
    glVertex2f(-18.3136517384226, -17.2579904637373);
    glVertex2f(-17.122841690561, -17.2579904637373);
    glVertex2f(-18.05126986347, -17.7121129396167);
    glVertex2f(-17.122841690561, -17.7121129396167);
    glVertex2f(-17.5769641664404, -16.2791042379528);
    glVertex2f(-17.5769641664404, -17.2378072425871);
    glVertex2f(-17.122841690561, -16.188279742777);
    glVertex2f(-17.122841690561, -18.1258689731957);
    glVertex2f(-16.2285357758943, -13.2465404754468);
    glVertex2f(-16.2285357758943, -13.9442605675424);
    glVertex2f(-15.724626820492, -12.8675320303579);
    glVertex2f(-15.724626820492, -14.3491104975237);
    glVertex2f(-15.2274605286865, -13.2465404754468);
    glVertex2f(-15.2274605286865, -13.9442605675424);
    glVertex2f(-16.2285357758943, -17.13043489641);
    glVertex2f(-16.2285357758943, -17.9028124558748);
    glVertex2f(-15.724626820492, -17.6013968229129);
    glVertex2f(-15.724626820492, -18.3549359053176);
    glVertex2f(-15.2274605286865, -17.13043489641);
    glVertex2f(-15.2274605286865, -17.9028124558748);
    glVertex2f(-10.0, -6.0);
    glVertex2f(-8.7665409818658, -6.0);
    glVertex2f(-11.1384651913831, -7.8492583533233);
    glVertex2f(-8.7665409818658,  -7.8492583533233);
    glVertex2f(-12.5111532445506, -9.0828832377058);
    glVertex2f(-9.0, -9.0828832377058);
    glVertex2f(-12.1338988294809,-12.4830312483625);
    glVertex2f(-12.1338988294809,-14.6277084460197);
    glVertex2f(-11.6276031218761,-12.4830312483625);
    glVertex2f(-11.6276031218761,-14.6277084460197);
    glVertex2f(-10.4462464707982,-12.4830312483625);
    glVertex2f(-10.4462464707982,-14.6277084460197);
    glVertex2f(-10.0243333811276,-12.4830312483625);
    glVertex2f(-10.0243333811276,-14.6277084460197);
    glVertex2f(-13.981530431386, -12.4830312483625);
    glVertex2f(-12.7649135483514,-12.4830312483625);
    glVertex2f(-12.7649135483514,-12.4830312483625);
    glVertex2f(-12.7649135483514,-14.6277084460197);
    glVertex2f(-12.7181205913116,-14.6277084460197);
    glVertex2f(-13.9698321921261,-14.6277084460197);
    glVertex2f(-13.6071867750677,-12.8859706006497);
    glVertex2f(-13.1977484009695,-12.8859706006497);
    glVertex2f(-13.1977484009695,-12.8859706006497);
    glVertex2f(-13.1977484009695,-13.2889099529368);
    glVertex2f(-13.1977484009695,-13.2889099529368);
    glVertex2f(-13.6071867750677,-13.2889099529368);
    glVertex2f(-13.6071867750677,-13.2889099529368);
    glVertex2f(-13.6071867750677,-12.8859706006497);
    glVertex2f(-13.6071867750677,-13.782835610579);
    glVertex2f(-13.1977484009695,-13.782835610579);
    glVertex2f(-13.1977484009695,-13.782835610579);
    glVertex2f(-13.1977484009695,-14.2687925702666);
    glVertex2f(-13.1977484009695,-14.2687925702666);
    glVertex2f(-13.6071867750677,-14.2687925702666);
    glVertex2f(-13.6071867750677,-14.2687925702666);
    glVertex2f(-13.6071867750677,-13.782835610579);
    glVertex2f(-13.981530431386, -16.7463895564326);
    glVertex2f(-12.5777417201922,-16.7463895564326);
    glVertex2f(-13.981530431386, -17.2273171704526);
    glVertex2f(-11.9343385608951,-17.2273171704526);
    glVertex2f(-13.9581339528661,-17.7472389153392);
    glVertex2f(-11.3728230764176,-17.7472389153392);
    glVertex2f(-5.8643430289515, -15.314795673714);
    glVertex2f(-6.8935035313622, -15.314795673714);
    glVertex2f(-6.8935035313622, -15.314795673714);
    glVertex2f(-6.8935035313622, -15.7576654240576);
    glVertex2f(-7.196554890652,  -15.7576654240576);
    glVertex2f(-6.5635494404383, -15.7576654240576);
    glVertex2f(-6.5635494404383, -15.7576654240576);
    glVertex2f(-6.5488283834566, -15.9637602218015);
    glVertex2f(-5.8643430289515, -15.8091891234936);
    glVertex2f(-6.2507269795769, -15.8165496519844);
    glVertex2f(-6.2507269795769, -15.8091891234936);
    glVertex2f(-6.2507269795769, -16.3501879675715);
    glVertex2f(-6.2507269795769, -15.9637602218015);
    glVertex2f(-6.6665968393103, -15.9637602218015);
    glVertex2f(-6.6665968393103, -15.9637602218015);
    glVertex2f(-6.6518757823286, -16.3501879675715);
    glVertex2f(-7.196554890652,  -16.3501879675715);
    glVertex2f(-6.0667137673055, -16.3501879675715);
    glVertex2f(-6.0667137673055, -16.3501879675715);
    glVertex2f(-6.0667137673055, -16.8028604697591);
    glVertex2f(-6.9573377146991, -16.3649090245532);
    glVertex2f(-6.9573377146991, -17.1929684797745);
    glVertex2f(-6.9573377146991, -17.1929684797745);
    glVertex2f(-6.5745902331746, -17.1929684797745);
    glVertex2f(-6.5745902331746, -17.1929684797745);
    glVertex2f(-6.5745902331746, -16.8065407340046);
    glVertex2f(-6.5745902331746, -16.8065407340046);
    glVertex2f(-5.8643430289515, -16.8065407340046);
    glVertex2f(-6.2603710233112, -16.8119429197953);
    glVertex2f(-6.2603710233112, -17.5097099731891);
    glVertex2f(-6.2603710233112, -17.5097099731891);
    glVertex2f(-5.8643430289515, -17.5097099731891);
    glVertex2f(-6.99392100252,   -17.5097099731891);
    glVertex2f(-6.99392100252,   -17.5097099731891);
    glVertex2f(-6.99392100252,   -18.0965499565562);
    glVertex2f(-6.5745902331746, -18.0965499565562);
    glVertex2f(-6.5745902331746, -18.0965499565562);
    glVertex2f(-6.5745902331746, -18.0965499565562);
    glVertex2f(-6.1065044423064, -17.5025533880261);
    glVertex2f(-6.1065044423064, -18.3756567779137);
    glVertex2f(-1.6935503138859, -17.5230691170585);
    glVertex2f(-1.6935503138859, -16.134407437384);
    glVertex2f(-1.6935503138859, -16.134407437384);
    glVertex2f(-0.0223328521938, -16.134407437384);
    glVertex2f(-1.4940524387778, -17.7812428377868);
    glVertex2f(-1.4940524387778, -16.3299935894509);
    glVertex2f(-1.4940524387778, -16.3299935894509);
    glVertex2f(0.0997540081704,  -16.3299935894509);
    glVertex2f(-2.5819438454349, -18.1703155012851);
    glVertex2f(-1.1485334945346, -18.1703155012851);
    glVertex2f(-1.1485334945346, -18.1703155012851);
    glVertex2f(-1.1568915723824, -16.6742195665262);
    glVertex2f(-0.8894330812523, -18.3876255253282);
    glVertex2f(-0.8894330812523, -16.5154160874177);
    glVertex2f(-2.0216472859083, -13.2665111364262);
    glVertex2f(-2.0216472859083, -12.5368767375824);
    glVertex2f(-1.6422152039067, -13.2665111364262);
    glVertex2f(-1.6422152039067, -12.5368767375824);
    glVertex2f(-1.2533523116855, -13.2665111364262);
    glVertex2f(-1.2533523116855, -12.5368767375824);
    glVertex2f(-2.0246506103061, -12.874319743229);
    glVertex2f(-1.2629935404182, -12.874319743229);
    glVertex2f(-2.8634375100561, -12.6204340532664);
    glVertex2f(-2.6641854495791, -12.6204340532664);
    glVertex2f(-2.8634375100561, -12.1287313878957);
    glVertex2f(-2.6609717066682, -12.1287313878957);
    glVertex2f(-2.8484518268625, -11.5756494466694);
    glVertex2f(-2.6730746624707, -11.5756494466694);
    glVertex2f(-2.6730746624707, -12.8460645155562);
    glVertex2f(-2.6730746624707, -12.4268703177417);
    glVertex2f(-2.6730746624707, -12.2899905796798);
    glVertex2f(-2.6730746624707, -11.9264037754529);
    glVertex2f(-2.6730746624707, -11.7553041028756);
    glVertex2f(-2.6730746624707, -11.3788848232054);
    glVertex2f(-1.9737890826313, -11.1730735815839);
    glVertex2f(-1.9737890826313, -11.4858982969155);
    glVertex2f(-1.9737890826313, -11.4858982969155);
    glVertex2f(-1.2655886854221, -11.4858982969155);
    glVertex2f(-1.2655886854221, -11.4858982969155);
    glVertex2f(-1.2655886854221, -11.1730735815839);
    glVertex2f(-1.6218612778832, -11.1730735815839);
    glVertex2f(-1.6218612778832, -11.4858982969155);
    glVertex2f(-1.6218612778832, -12.1463060292823);
    glVertex2f(-1.6218612778832, -11.8552052525154);
    glVertex2f(-1.9737890826313, -12.1463060292823);
    glVertex2f(-1.9737890826313, -11.8552052525154);
    glVertex2f(-1.9737890826313, -11.8552052525154);
    glVertex2f(-1.274278260848,  -11.8552052525154);
    glVertex2f(-1.274278260848,  -11.8552052525154);
    glVertex2f(-1.274278260848,  -12.1463060292823);
    glVertex2f(0.2231475116637,  -9.1461536871303);
    glVertex2f(-0.1130287841462, -9.1461536871303);
    glVertex2f(0.2231475116637,  -9.3080163480758);
    glVertex2f(-0.1130287841462, -9.3080163480758);
    glVertex2f(0.2231475116637,  -9.4624084246699);
    glVertex2f(-0.1130287841462, -9.4624084246699);
    glVertex2f(2.4955857035688, -11.3500744130817);
    glVertex2f(2.8089082933177, -11.3500744130817);
    glVertex2f(2.4955857035688, -11.5025016189056);
    glVertex2f(2.8089082933177, -11.5025016189056);
    glVertex2f(2.4955857035688, -11.646460646628);
    glVertex2f(2.8089082933177, -11.646460646628);
    glVertex2f(7.8193249717015, -10.3167647514729);
    glVertex2f(8.6096425554131, -10.3167647514729);
    glVertex2f(8.0, -11.0061907287532);
    glVertex2f(8.6096425554131, -11.0061907287532);
    glVertex2f(7.8193249717015, -14.7728107021869);
    glVertex2f(8.6096425554131, -14.7728107021869);
    glVertex2f(8.6096425554131, -14.0833847249067);
    glVertex2f(9.3326990681705, -14.0833847249067);
    glVertex2f(8.6096425554131, -10.3167647514729);
    glVertex2f(8.6096425554131, -14.7728107021869);
    glVertex2f(8.9795784456611, -14.7055496312328);
    glVertex2f(9.3326990681705, -14.7055496312328);
    glVertex2f(8.4751204135047, -16.1180321212704);
    glVertex2f(9.3326990681705, -16.1180321212704);
    glVertex2f(8.6600883586287, -17.3623619339226);
    glVertex2f(9.3326990681705, -17.3791772016612);
    glVertex2f(9.3326990681705, -14.0833847249067);
    glVertex2f(9.3326990681705, -17.8163741628633);
    glVertex2f(7.8193249717015, -17.7995588951248);
    glVertex2f(9.3326990681705, -17.8163741628633);
    glVertex2f(8.6096425554131, -14.4652528785139);
    glVertex2f(8.0, -14.4652528785139);
    glVertex2f(13.4566613313741, -11.8167243802525);
    glVertex2f(13.090811539549, -11.8167243802525);
    glVertex2f(13.090811539549, -11.8167243802525);
    glVertex2f(13.090811539549, -12.1572852482286);
    glVertex2f(13.090811539549, -12.1572852482286);
    glVertex2f(13.4566613313741,-12.1572852482286);
    glVertex2f(13.4566613313741,-12.1572852482286);
    glVertex2f(13.4566613313741,-12.4977782782918);
    glVertex2f(13.4566613313741,-12.4977782782918);
    glVertex2f(13.090811539549, -12.4977782782918);
    glVertex2f(13.090811539549, -12.4977782782918);
    glVertex2f(13.090811539549, -12.8295407178405);
    glVertex2f(13.090811539549, -12.8295407178405);
    glVertex2f(13.4566613313741,-12.8295407178405);
    glVertex2f(13.4566613313741,-12.8295407178405);
    glVertex2f(13.4566613313741,-13.1613031573893);
    glVertex2f(13.4566613313741,-13.1613031573893);
    glVertex2f(13.090811539549, -13.1613031573893);
    glVertex2f(13.090811539549, -13.1613031573893);
    glVertex2f(13.090811539549, -13.4406820538514);
    glVertex2f(13.090811539549, -13.4406820538514);
    glVertex2f(13.4566613313741,-13.4406820538514);
    glVertex2f(13.4566613313741,-13.4406820538514);
    glVertex2f(13.4566613313741,-13.8073668554579);
    glVertex2f(13.4566613313741,-13.8073668554579);
    glVertex2f(13.090811539549, -13.8073668554579);
    glVertex2f(13.090811539549, -13.8073668554579);
    glVertex2f(13.090811539549, -14.0954763424344);
    glVertex2f(13.090811539549, -14.0954763424344);
    glVertex2f(13.4566613313741,-14.0954763424344);
    glVertex2f(13.4566613313741,-14.0954763424344);
    glVertex2f(13.4566613313741,-14.4970835060987);
    glVertex2f(13.4566613313741,-14.4970835060987);
    glVertex2f(13.090811539549, -14.4970835060987);
    glVertex2f(13.090811539549, -14.4970835060987);
    glVertex2f(13.090811539549, -14.8550377171908);
    glVertex2f(13.090811539549, -14.8550377171908);
    glVertex2f(13.4566613313741, -14.8550377171908);
    glVertex2f(11.8305870757696, -9.0064803098566);
    glVertex2f(13.0797094695669, -9.0064803098566);
    glVertex2f(11.8570515332653, -10.5467117361066);
    glVertex2f(13.1379312760575, -10.5467117361066);
    glVertex2f(0.4863237404037, -8.1493983457196);
    glVertex2f(2.0943420561494, -8.1493983457196);
    glVertex2f(2.0943420561494, -8.1493983457196);
    glVertex2f(2.0943420561494, -16.9297551408614);
    glVertex2f(2.0943420561494, -16.9297551408614);
    glVertex2f(0.4863237404037, -16.9297551408614);
    glVertex2f(0.4863237404037, -16.9297551408614);
    glVertex2f(0.4863237404037, -15.2945982515467);
    glVertex2f(0.4863237404037, -15.2945982515467);
    glVertex2f(-2.2581631223606, -15.2945982515467);
    glVertex2f(-2.2581631223606, -15.2945982515467);
    glVertex2f(-2.2581631223606, -14.0373187650772);
    glVertex2f(-2.2581631223606, -14.0373187650772);
    glVertex2f(0.4863237404037, -14.0373187650772);
    glVertex2f(0.4863237404037, -14.0373187650772);
    glVertex2f(0.4863237404037, -8.1493983457196);
    glVertex2f(-6.1065044423064, -18.0965499565562);
    glVertex2f(-7.1907270945029, -18.0965499565562);
    glVertex2f(-7.0096073255991, -18.0965499565562);
    glVertex2f(-7.0096073255991, -17.5360431193447);
    glVertex2f(-7.0096073255991, -17.5360431193447);
    glVertex2f(-5.8916832566236, -17.5360431193447);
    glVertex2f(-6.5640012281753, -18.0965499565562);
    glVertex2f(-6.5640012281753, -17.5360431193447);

     glVertex2f(15.2375803360651, -18.3797199474651);
    glVertex2f(15.2375803360651, -17.3045367684096);
    glVertex2f(15.4839764812653, -18.3797199474651);
    glVertex2f(15.4839764812653, -17);
    glVertex2f(16.5, -18);
    glVertex2f(17.3543472198307, -18);
    glVertex2f(17.8079401234948, -17.5621327383916);
    glVertex2f(16.9007543161667, -17.5621327383916);
    glVertex2f(20.9590318940722, -16.6759361093509);
    glVertex2f(20.9590318940722, -16.0683906337916);
    glVertex2f(20.9590318940722, -16.0683906337916);
    glVertex2f(23.0990428229079, -16.0593227908728);
    glVertex2f(23.0990428229079, -16.0593227908728);
    glVertex2f(23.0990428229079, -15.4608451582324);
    glVertex2f(21.3126777679052, -16.9933106115087);
    glVertex2f(21.3126777679052, -17.4058974643139);
    glVertex2f(21.3126777679052, -17.4058974643139);
    glVertex2f(21.9474267722209, -17.4013635428545);
    glVertex2f(21.9474267722209, -17.4013635428545);
    glVertex2f(21.94742677222, -15.1162671273182);
    glVertex2f(21.9474267722209, -15.1162671273182);
    glVertex2f(22.7635326349124, -15.1162671273182);
    glVertex2f(22.7635326349124, -15.1162671273182);
    glVertex2f(22.7635326349124, -15.5741931947173);
    glVertex2f(23.0525629304965, -16.6515772402924);
    glVertex2f(23.0525629304965, -16.8980982608614);
    glVertex2f(23.0525629304965, -16.8980982608614);
    glVertex2f(22.5595061692395, -16.8980982608614);
    glVertex2f(22.5595061692395, -16.8980982608614);
    glVertex2f(22.5595061692395, -16.0683906337916);
    glVertex2f(21.1177191451511, -15.6195324093113);
    glVertex2f(21.1177191451511, -15.4653790796918);
     glVertex2f(21.1177191451511, -15.4653790796918);
    glVertex2f(21.4486954116871, -15.4699130011512);
    glVertex2f(21.4486954116871, -15.4699130011512);
    glVertex2f(21.4486954116871, -16.0593227908728);
    glVertex2f(21.2948968662277, -6.248332660948);
    glVertex2f(22.850448464132, -6.248332660948);
    glVertex2f(21.076998587922, -7.5375641409232);
    glVertex2f(22.9109757636614, -7.5375641409232);
    glVertex2f(21.2404222966513, -8.4999482034398);
    glVertex2f(22.8262375443203, -8.4999482034398);
    glVertex2f(4.3407624196601, -18.217643404472);
    glVertex2f(4.3407624196601, -13.2174243022256);
    glVertex2f(4.7124003259081, -18.217643404472);
    glVertex2f(4.7124003259081, -13.2174243022256);
    glVertex2f(5.1009308642584, -18.217643404472);
    glVertex2f(5.1009308642584,-13.2174243022256);
    glEnd();

    glPointSize(3.0);
    glBegin(GL_POINTS);
	glVertex2f(-23.4762843038129, -6.2142575025084);
    glVertex2f(-23.1812333466068, -6.1931824341365);
    glVertex2f(-23.3182212910239, -6.43027695332);
    glVertex2f(-21.8798478746441, -6.3196328443677);
    glVertex2f(-21.6322158212747, -6.3090953101818);
    glVertex2f(-21.7902788340637, -6.5567273635512);
	glVertex2f(-23.4762843038129, -6.2142575025084);
    glVertex2f(-23.1812333466068, -6.1931824341365);
    glVertex2f(-23.3182212910239, -6.43027695332);
    glVertex2f(-21.8798478746441, -6.3196328443677);
    glVertex2f(-21.6322158212747, -6.3090953101818);
    glVertex2f(-21.7902788340637, -6.5567273635512);
    glVertex2f(-17.8782517455588, -14.2749049535804);
    glVertex2f(-17.8782517455588, -14.5648063736781);
    glVertex2f(-17.8782517455588, -14.8093015472544);
    glVertex2f(-17.8782517455588, -15.0712606618005);
    glVertex2f(-17.5743791726854, -14.8093015472544);
    glVertex2f(-17.5743791726854, -15.0712606618005);
    glVertex2f(-17.5743791726854, -15.3122630471829);
    glVertex2f(-17.5743791726854, -15.6091500436685);
    glVertex2f(-16.0184069110242, -13.5858272053562);
    glVertex2f(-15.4282315165275, -13.5858272053562);
    glVertex2f(-13.2348579498968, -11.5059016736305);
    glVertex2f(-12.8750201303386, -11.5059016736305);
    glVertex2f(-13.2348579498968, -11.9197151661224);
    glVertex2f(-12.8750201303386, -11.9197151661224);
    glVertex2f(-11.4986404705285, -11.5059016736305);
    glVertex2f(-11.1298067054814, -11.5059016736305);
    glVertex2f(-11.4986404705285, -11.9197151661224);
    glVertex2f(-11.1298067054814, -11.9197151661224);
    glVertex2f(-9.7304993139851,  -11.5059016736305);
    glVertex2f(-9.389333287647,   -11.5059016736305);
    glVertex2f(-9.7304993139851,  -11.9197151661224);
    glVertex2f(-9.389333287647,   -11.9197151661224);
    glVertex2f(-11.8837208831245, -13.5796870622854);
    glVertex2f(-10.2403290230321, -13.5796870622854);
    glVertex2f(-12.7411427231727, -9.2766996798212);
    glVertex2f(-12.7411427231727, -8.9670751264705);
    glVertex2f(-11.4311926897657, -8.0382014664183);
    glVertex2f(-11.4311926897657, -7.6870820336667);
    glVertex2f(-10.156754282755, -5.9048362487782);
    glVertex2f(-10.156754282755, -6.2394833965988);
    glVertex2f(-6.7950748178015, -14.3262554752539);
    glVertex2f(-6.1520607479766, -14.3262554752539);
    glVertex2f(16.7252780469521, -15.9188116553527);
    glVertex2f(16.9308154867428, -15.9188116553527);
    glVertex2f(17.1445744241252, -15.9188116553527);
    glVertex2f(17.1445744241252, -15.7050527179703);
    glVertex2f(17.1445744241252, -16.1818995782848);
    glVertex2f(17.1445744241252, -15.0555544082315);
    glVertex2f(17.1445744241252, -14.800687982891);
    glVertex2f(17.1445744241252, -14.578707547917);
    glVertex2f(17.3418903663244, -14.800687982891);
    glVertex2f(17.5309848109319, -14.800687982891);
    glVertex2f(16.9308154867428, -12.8686360488579);
    glVertex2f(16.9308154867428, -12.6548771114755);
    glVertex2f(21.0394109164357, -13.859946768955);
    glVertex2f(21.7013664692074, -13.859946768955);
    glVertex2f(22.3219497999309, -13.859946768955);
    glVertex2f(22.9342586862447, -13.859946768955);
    glVertex2f(21.0394109164357, -9.7644310804855);
    glVertex2f(21.7013664692074, -9.7644310804855);
    glVertex2f(22.3219497999309, -9.7644310804855);
    glVertex2f(22.9342586862447, -9.7644310804855);
    glVertex2f(16.9308154867428, -12.3779129814767);
    glVertex2f(-5.0,             -15.9736445472432);
    glVertex2f(-4.1842315224687, -15.9736445472432);
    glVertex2f(-4.5781575545874, -16.5132692487757);
    glVertex2f(-4.5997425426487, -15.5743222681092);
    glVertex2f(6.0522633516092,  -14.4680943545306);
    glVertex2f(6.0522633516092,  -14.2657084783501);
    glVertex2f(6.0522633516092,  -14.0665350763947);
    glVertex2f(7.3147657220687,  -14.0215604372435);
    glVertex2f(7.3147657220687,  -13.7741999219117);
    glVertex2f(7.3147657220687,  -13.5204144581298);
    glVertex2f(14.9606403886024, -15.8894691795895);
    glVertex2f(14.9606403886024, -15.5762991601594);
    glVertex2f(14.9606403886024, -15.2875319993863);
    glVertex2f(15.2046689751712, -15.2875319993863);
    glVertex2f(15.2046689751712, -15.0272348403795);
    glVertex2f(15.2046689751712, -14.7181319640589);
    glVertex2f(15.5015704221633, -15.2875319993863);
    glVertex2f(15.5015704221633, -15.6210377343637);
    glVertex2f(15.5015704221633, -15.9138720382464);
    glVertex2f(-1.830714231444,  -11.6366710654242);
    glVertex2f(-1.4382779610076, -11.6366710654242);
	glEnd();

    }
}

//AK016
void A_Details2(float r, float g, float b,float r1, float g1, float b1,float r2, float g2, float b2 ){

    glColor3f(r1,g1,b1);
    glPushMatrix();
    glTranslatef(12.5f, -09.75f, 1.f);
    glScaled(0.7,1.0,0);
    glutSolidSphere(0.5f, 80, 80);
    glPopMatrix();

    glColor3f(r1,g1,b1);
    glPushMatrix();
    glTranslatef(-5.0f, -5.0f, 1.0f);
    glScaled(0.9,3.0,0);
    glutSolidSphere(0.8f, 80, 80);
    glPopMatrix();

    glColor3f(r1,g1,b1);
    glPushMatrix();
    glTranslatef(9.3f, -08.0f, 1.0f);
    glScaled(0.7,1.0,0);
    glutSolidSphere(1.25f, 80, 80);
    glPopMatrix();

     glColor3f(r1,g1,b1);
    glPushMatrix();
    glTranslatef(-12.1f, -08.1f, 1.f);
    glScaled(0.7,1.0,0);
    glutSolidSphere(0.5f, 80, 80);
    glPopMatrix();

    glColor3f(r1,g1,b1);
    glPushMatrix();
    glTranslatef(-10.8f, -06.30f, 1.f);
    glScaled(0.7,1.0,0);
    glutSolidSphere(0.5f, 80, 80);
    glPopMatrix();

    glColor3f(r1,g1,b1);
    glPushMatrix();
    glTranslatef(-13.4f, -09.40f, 1.f);
    glScaled(0.7,1.0,0);
    glutSolidSphere(0.5f, 80, 80);
    glPopMatrix();

    glColor3f(r,g,b); //light details
    {
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2f(-5.1669728742793, -17.5360431193447);
    glVertex2f(-4.4155809421732, -17.5360431193447);
    glVertex2f(-4.9687529167298, -17.7803607414405);
    glVertex2f(-4.0329703264382, -17.7803607414405);
    glVertex2f(-5.1669728742793, -17.97858069899);
    glVertex2f(-4.2588488827155, -17.97858069899);
    glVertex2f(-5, -18.1860201894487);
    glVertex2f(-4.0329703264382, -18.1860201894487);
    glVertex2f(6.2771946107226, -16.8921596809185);
    glVertex2f(6.2771946107226, -16.2196329871756);
    glVertex2f(6.4244835147241, -16.8921596809185);
    glVertex2f(6.4244835147241, -16.2196329871756);
    glVertex2f(7.0303133462776, -16.0779021550231);
    glVertex2f(7.0303133462776, -15.6276983352448);
    glVertex2f(7.1331376754863, -16.0779021550231);
    glVertex2f(7.1331376754863, -15.6276983352448);
    glVertex2f(6.3657197254525, -15.2362423108578);
    glVertex2f(6.8422910701419, -15.2362423108578);
    glVertex2f(6.3657197254525, -15.078862936565);
    glVertex2f(6.8422910701419, -15.078862936565);
    glVertex2f(6.5007725451755, -17.1835802614836);
    glVertex2f(7.0058627953379, -17.1835802614836);
    glVertex2f(6.5007725451755, -17.2826129052664);
    glVertex2f(7.0058627953379, -17.2834871683062);
    glVertex2f(6.2638289723784, -13.1334437795209);
    glVertex2f(6.5030321969472, -13.1334437795209);
    glVertex2f(6.8611730542743, -13.1334437795209);
    glVertex2f(7.1001106870326, -13.1334437795209);
    glVertex2f(6.5811370554396, -15.9477779537538);
    glVertex2f(6.5811370554396, -15.7489037284673);
    glVertex2f(6.5811370554396, -15.7489037284673);
    glVertex2f(6.7785271447165, -15.7489037284673);
    glVertex2f(6.7785271447165, -15.7489037284673);
    glVertex2f(6.7785271447165, -15.5867441841198);
    glVertex2f(14.95212767489, -15.0586432131418);
    glVertex2f(14.95212767489, -13.4446989805018);
    glVertex2f(15.5016094790969, -13.4446989805018);
    glVertex2f(15.5016094790969, -15.0586432131418);
    glVertex2f(15.2062438110597, -14.4885940812358);
    glVertex2f(15.2062438110597, -13.1210105771734);
    glVertex2f(17.8, -12.8492266439309);
    glVertex2f(17.2341969148452, -12.8492266439309);
    glVertex2f(17.8, -12.6282815505583);
    glVertex2f(17.2837968337656, -12.6282815505583);
    glVertex2f(17.8, -12.4);
    glVertex2f(17.3379058362242, -12.4);
    glVertex2f(21.3823432378439, -14.0315259059183);
    glVertex2f(21.3823432378439, -9.5767734171115);
    glVertex2f(22.0371294170589, -14.0315259059183);
    glVertex2f(22.0371294170589, -9.5767734171115);
    glVertex2f(22.6334210404594, -14.0315259059183);
    glVertex2f(22.6334210404594, -9.5767734171115);
    glVertex2f(20.7214892885616, -6.769916070391);
    glVertex2f(20.9472864520975, -6.769916070391);
    glVertex2f(20.7213785039743, -6.9131098689412);
    glVertex2f(20.9488026128232, -6.9131098689412);
    glVertex2f(20.718346182523, -7.0616936200558);
    glVertex2f(20.9563834164515, -7.0616936200558);
    glVertex2f(23.3453325014361, -6.769916070391);
    glVertex2f(23.110566064668, -6.769916070391);
    glVertex2f(23.3453325014361, -6.9131098689412);
    glVertex2f(23.110566064668, -6.9131098689412);
    glVertex2f(23.342723985472, -7.0616936200558);
    glVertex2f(23.110566064668, -7.0616936200558);
    glEnd();

    glPointSize(2.0);
    glBegin(GL_POINTS);
    glVertex2f(0.7964256674583, -7.858910303837);
    glVertex2f(0.7964256674583, -8.0183344920696);
    glVertex2f(0.9458858439264, -8.0183344920696);
    glVertex2f(1.0953460203945, -8.0183344920696);
    glVertex2f(1.2414848596077, -8.0183344920696);
    glVertex2f(1.4009090478403, -8.0183344920696);
    glVertex2f(1.4009090478403, -7.8655529783467);
    glVertex2f(1.6001892831311, -7.8655529783467);
    glVertex2f(1.7944875125395, -7.8655529783467);
    glVertex2f(1.9954284164577, -7.8655529783467);
    glVertex2f(1.9954284164577, -8.0166738234422);
    glVertex2f(6.3241380086204, -17.980640692445);
    glVertex2f(6.3241380086204, -17.8925916900209);
    glVertex2f(6.3241380086204, -17.7939768073059);
    glVertex2f(6.4227528913353, -17.7939768073059);
    glVertex2f(6.5319336543412, -17.7939768073059);
    glVertex2f(6.6340704971531, -17.7939768073059);
    glVertex2f(6.4775822927898, -17.9278112909905);
    glVertex2f(6.5799760700913, -17.9278112909905);
    glVertex2f(6.6763340183167, -17.9278112909905);
    glVertex2f(6.7784708611286, -17.9278112909905);
    glVertex2f(6.7784708611286, -17.825281688573);
    glVertex2f(6.7784708611286, -17.7235376053667);
    glVertex2f(14.9511544869183, -15.8726373850028);
    glVertex2f(15.4904116417699, -15.9079985099111);
	glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-8.3555776083247,-18.3615556883494);
    glVertex2f(-8.3555776083247,-6.1460472111446);
    glEnd();
}
    glLineWidth(7.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(5.2613267864385, -13.6948642869712);
    glVertex2f(6.0666771695074, -13.6948642869712);
    glVertex2f(5.2613267864385, -16.1020654319684);
    glVertex2f(6.0666771695074, -16.1020654319684);
    glVertex2f(10.7445272823917, -9.9315661441931);
    glVertex2f(11.4983018090856, -9.9315661441931);
    glVertex2f(15.7142868492005, -15.2298331015298);
    glVertex2f(16.4985276270709, -15.2298331015298);
    glVertex2f(15.7142868492005, -17.6166284904961);
    glVertex2f(16.4985276270709, -17.6166284904961);
    glEnd();

glBegin(GL_QUADS);
glColor3f(0.55,0.55,0.55);
glVertex2f(-4.8058340684966, -16.3447564491564);
glVertex2f(-4.8058340684966, -15.7332007554331);
glVertex2f(-4.3674622880401, -15.7169647635644);
glVertex2f(-4.3674622880401, -16.3447564491564);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.55,0.55,0.55);
glVertex2f(-6.764977087327,  -17.7843477281864);
glVertex2f(-6.764977087327,  -17.2215000100694);
glVertex2f(-6.3861372770559, -17.2215000100694);
glVertex2f(-6.3861372770559, -17.7843477281864);
glEnd();

glColor3f(r2,g2,b2);
glLineWidth(2.0);
glBegin(GL_LINES);
glVertex2f(4.3271464268392, -13.310547955143);
glVertex2f(5.1291424023939, -13.310547955143);
glVertex2f(4.3271464268392, -13.5272423575107);
glVertex2f(5.1291424023939, -13.5272423575107);
glVertex2f(4.3271464268392, -13.721711692969);
glVertex2f(5.1291424023939, -13.721711692969);
glVertex2f(4.3271464268392, -13.9161810284272);
glVertex2f(5.1291424023939, -13.9161810284272);
glVertex2f(4.3271464268392, -14.1106503638854);
glVertex2f(5.1291424023939, -14.1106503638854);
glVertex2f(4.3271464268392, -14.3106759660711);
glVertex2f(5.1291424023939, -14.3106759660711);
glVertex2f(4.3271464268392, -14.5662642355305);
glVertex2f(5.1291424023939, -14.5662642355305);
glVertex2f(4.3271464268392, -14.8718589055363);
glVertex2f(5.1291424023939, -14.8718589055363);
glVertex2f(4.3271464268392, -15.2635670260747);
glVertex2f(5.1291424023939, -15.2635670260747);
glVertex2f(4.3271464268392, -15.6988501134348);
glVertex2f(5.1291424023939, -15.6988501134348);
glVertex2f(4.3271464268392, -16.3003321977871);
glVertex2f(5.1291424023939, -16.3003321977871);
glVertex2f(4.3271464268392, -17.1471556586514);
glVertex2f(5.1291424023939, -17.1471556586514);
    glEnd();
}

//AK017
void A_stars(){

glPointSize(2.5);
glBegin(GL_POINTS);
glColor3f(1.0,1.0,1.0);
glVertex2f(-9.1987134249369+ StarsPosition, 9.0389133797615+ StarsPosition);
glVertex2f(-4.0683819559985+ StarsPosition, 6.9216337259139+ StarsPosition);
glVertex2f(0.4023354669335+ StarsPosition, 5.6594093168894+ StarsPosition);
glVertex2f(2.1246610315057+ StarsPosition, 8.2652919677787+ StarsPosition);
glVertex2f(-2.7857990887639+ StarsPosition, 11.1969099500292+ StarsPosition);
glVertex2f(-9.1254229753806+ StarsPosition, 13.1513219381962+ StarsPosition);
glVertex2f(-4+ StarsPosition, 14+ StarsPosition);
glVertex2f(2.0513705819494+ StarsPosition, 12.725586606835+ StarsPosition);
glVertex2f(6+ StarsPosition, 12+ StarsPosition);
glVertex2f(6.3388618809908+ StarsPosition, 7.4916705557959+ StarsPosition);
glVertex2f(10+ StarsPosition, 10+ StarsPosition);
glVertex2f(12.6051953180512+ StarsPosition, 5.3336739855282+ StarsPosition);
glVertex2f(15.9399107728611+ StarsPosition, 8.346725800619+ StarsPosition);
glVertex2f(17.0759127409832+ StarsPosition, 11.3597776157098+ StarsPosition);
glVertex2f(16.5995248188675+ StarsPosition, 14.20996176512+ StarsPosition);
glVertex2f(10.2965461570289+ StarsPosition, 14.8614324278423+ StarsPosition);
glVertex2f(21.3634040400246+ StarsPosition, 11.8890975291717+ StarsPosition);
glVertex2f(-18.7838160710945+ StarsPosition, 5.8163836236348+ StarsPosition);
glVertex2f(-22.2324533587483+ StarsPosition, 7.9451720728039+ StarsPosition);
glVertex2f(-22.2324533587483+ StarsPosition, 13.8206281925104+ StarsPosition);
glVertex2f(23.9026499116427+ StarsPosition, 9.4778997562056+ StarsPosition);
glVertex2f(23.7493771433025+ StarsPosition, 13.9057797304771+ StarsPosition);
glVertex2f(-12.2324533587483+ StarsPosition, 13.8206281925104+ StarsPosition);
glVertex2f(13.9026499116427+ StarsPosition, 9.4778997562056+ StarsPosition);
glVertex2f(13.7493771433025+ StarsPosition, 13.9057797304771+ StarsPosition);
glVertex2f(-12.2324533587483 + StarsPosition, 13.8206281925104 + StarsPosition);
glVertex2f(-13.9026499116427 + StarsPosition, 9.4778997562056 + StarsPosition);
glVertex2f(-13.7493771433025 + StarsPosition, 13.9057797304771 + StarsPosition);
glVertex2f(-6.0 + StarsPosition, 16.0 + StarsPosition);
glVertex2f(0.0 + StarsPosition, 16.0 + StarsPosition);
glVertex2f(4.0 + StarsPosition, 16.0 + StarsPosition);
glVertex2f(-5.0 + StarsPosition, 18.0 + StarsPosition);
glVertex2f(-1.0 + StarsPosition, 18.0 + StarsPosition);
glVertex2f(5.0 + StarsPosition, 18.0 + StarsPosition);
glVertex2f(-8.0 + StarsPosition, 17.0 + StarsPosition);
glVertex2f(5.0 + StarsPosition, 17.0 + StarsPosition);
glVertex2f(8.0 + StarsPosition, 17.0 + StarsPosition);
glEnd();
}

//AK018
void A_FlyingObject1(float r1, float g1, float b1){
    if (liftUp) {

        FlyingObject1PositionY += FlyingObject1MoveSpeed;
        FlyingObject1PositionY=0.0;
        FlyingObject1PositionX -= FlyingObject1MoveSpeed;
    }
    glPushMatrix();
    glTranslatef(FlyingObject1PositionX, FlyingObject1PositionY, 0.0);
     glColor3f(r1,g1,b1); //car1
    {

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(5.3900861922515,3.6772249918159);
    glVertex2f(6.0484285082092,3.6772249918159);
    glVertex2f(5.9841999895792,4.1830245760274);
    glVertex2f(5.9841999895792,3.7896248994185);
    glEnd();
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(5.5472045991637,3.8117678164119);
    glVertex2f(6.2,3.8117678164119);
    glEnd();
    }
    glColor3f(0.008, 0.647, 0.949);
    {
    glLineWidth(1.0); // car1
    glBegin(GL_LINES);
    glVertex2f(6.5472045991637,3.8117678164119);
    glVertex2f(7.5,3.8117678164119);
    glVertex2f(7.55,3.8117678164119);
    glVertex2f(7.7,3.8117678164119);
    glVertex2f(6.3472045991637,3.707678164119);
    glVertex2f(7.2,3.707678164119);
    glEnd();
    glPopMatrix();
    }

}

////AK019
void A_FlyingObject2(float r2, float g2, float b2){

  if (liftUpObject2) {
        FlyingObject2PositionY += FlyingObject2MoveSpeed;
        FlyingObject2PositionY=12.0;
        FlyingObject2PositionX += FlyingObject2MoveSpeed;
    }

    glPushMatrix();
    glTranslatef(FlyingObject2PositionX, FlyingObject2PositionY, 0.0);
    glColor3f(r2,g2,b2); //car2
    {
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(-13.0326000647958,-2.2571341762015);
    glVertex2f(-13.0326000647958,-3.2822514045345);
    glVertex2f(-13.0326000647958,-3.2822514045345);
    glVertex2f(-10.504082333094, -3.2822514045345);
    glEnd();
    glLineWidth(8.0);
    glBegin(GL_LINES);
    glVertex2f(-11.1711306,-2.2647146);
    glVertex2f(-11.1711306,-3.0047146);
    glVertex2f(-11.1711306,-3.0047146);
    glVertex2f(-10.5849414037514,-3.0047146);
    glVertex2f(-12.8358581912598,-2.5709755724199);
    glVertex2f(-11.2277999160276,-2.5709755724199);
    glVertex2f(-12.8358581912598,-2.9709755724199);
    glVertex2f(-11.2277999160276,-2.9709755724199);
    glEnd();
    }
    glLineWidth(2.0);   //car 2
    glBegin(GL_LINES);
    glVertex2f(-13.8103655093539,-2.9667280538373);
    glVertex2f(-15.2717177445726,-2.9667280538373);
    glVertex2f(-13.6103655093539,-2.4812282356749);
    glVertex2f(-15.7999093114592,-2.4812282356749);
    glVertex2f(-15.5717177445726,-2.9667280538373);
    glVertex2f(-15.7717177445726,-2.9667280538373);
    glEnd();
    glPopMatrix();
    }

//AK020
void A_FlyingObject3(float r3, float g3, float b3){
    glColor3f(r3,g3,b3); //car3
    {
    glPushMatrix();
    glTranslatef(FlyingObjectPositionX,10,0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(-11.5869529443102, 3.6288103417649);
    glVertex2f(-11.5869529443102, 2.4329444664291);
    glVertex2f(-11.8096310282362, 2.8370660433613);
    glVertex2f(- 9.1622360304492,  2.8370660433613);
    glEnd();
    glLineWidth(7.0);
    glBegin(GL_LINES);
    glVertex2f(-12.0000,2.5);
    glVertex2f(-9.1622360304492,2.5);
    glVertex2f(-11.8096310282362,2.8370660433613);
    glVertex2f(-10.5354175479929,2.8370660433613);
    glEnd();
    glLineWidth(8.0);
    glBegin(GL_LINES);
    glVertex2f(-11.1711306,-2.2647146);
    glVertex2f(-11.1711306,-3.0047146);
    glVertex2f(-11.1711306,-3.0047146);
    glVertex2f(-10.5849414037514,-3.0047146);
    glVertex2f(-12.8358581912598,-2.5709755724199);
    glVertex2f(-11.2277999160276,-2.5709755724199);
    glVertex2f(-12.8358581912598,-2.9709755724199);
    glVertex2f(-11.2277999160276,-2.9709755724199);
    glEnd();
    }
    glColor3f(0.008, 0.647, 0.949);
    glLineWidth(1.2);
    glBegin(GL_LINES);
    glVertex2f(-12.0096310282362,2.8370660433613); //car3
    glVertex2f(-12.2869529443102, 2.8370660433613);
    glVertex2f(-12.4869529443102, 2.8370660433613);
    glVertex2f(-13.6869529443102, 2.8370660433613);
    glVertex2f(-12.0869529443102, 3.2370660433613);
    glVertex2f(-12.8869529443102, 3.2370660433613);
    glVertex2f(-12.0869529443102, 2.5370660433613);
    glVertex2f(-12.8869529443102, 2.5370660433613);
    glEnd();
    glPopMatrix();
    }

//AK021
void A_FlyingObject4(float r4, float g4, float b4){
     glColor3f(r4,g4,b4); //car4
    {
    glPushMatrix();
    glTranslatef(-FlyingObjectPositionX,7.5,0);
    glLineWidth(3.0);
    glLineWidth(9.0);
    glBegin(GL_LINES);
    glVertex2f(5.8223674440773,-1.0996711183815);
    glVertex2f(8,-1.0996711183815);
    glVertex2f(5.120052234282,-1.4933932814486);
    glVertex2f(8,-1.4933932814486);
    glEnd();
    glPopMatrix();
    }

    }

//**************animation*******************///
void MoveStars(int value) {
    if (StarsPosition > 0) {
        StarsPosition -= StarsMoveSpeed;
    } else {
        StarsPosition = 4.0;
    }

    glutPostRedisplay();
    glutTimerFunc(10, MoveStars, 0);
}
void MoveClouds(int value) {
    CloudPositionX += CloudMoveSpeed;
    if (CloudPositionX > 30) {
        CloudPositionX = -30;
    }
    glutPostRedisplay();
    glutTimerFunc(10, MoveClouds, 0);
}
void MoveFlyingObject(int value) {
    FlyingObjectPositionX += FlyingObjectMoveSpeed;
    if (FlyingObjectPositionX > 35) {
        FlyingObjectPositionX = -25;
    }

    glutPostRedisplay();
    glutTimerFunc(100, MoveFlyingObject, 0);
}
void MoveFlyingObject1(int value) {
    FlyingObject1PositionX += FlyingObject1MoveSpeed;
    if (FlyingObject1PositionX > 35) {
        FlyingObject1PositionX = -25;
    }
    if (!liftUp) {
        FlyingObject1PositionX = -15.0;
    }
    glutPostRedisplay();
    glutTimerFunc(1000, MoveFlyingObject1, 0);
}
void MoveFlyingObject2(int value) {
    FlyingObject2PositionX += FlyingObject2MoveSpeed;
    if (FlyingObject2PositionX > 35) {
        FlyingObject2PositionX = -25;
    }
     if (!liftUpObject2) {
        FlyingObject2PositionY = -2.8;
        FlyingObject2PositionX = 17.8;
     }
    glutPostRedisplay();
    glutTimerFunc(1000, MoveFlyingObject2, 0);

}
void A_Display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (dayBackground)
        {
    glClearColor(0.38, 0.722, 0.871, 1.0); // Night Scene
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-25.0, 25.0, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    A_GradientEffect(31,49,84, 61,99,173);
    A_stars();
    A_SunMoon(0.78f,0.78f,0.78f,-20,17);
    A_Cloud();
    A_FlyingObject1(1,0,0);
    A_FlyingObject2(0,1,0);
    A_FlyingObject3(0,0,1);
    A_FlyingObject4(0.5,0.5,0);
    A_AdvancedBuildingtype9(0,0,0);
    A_AdvancedBuildingtype1(0,0,0);
    A_AdvancedBuildingtype2(0,0,0);
    A_AdvancedBuildingtype3(0,0,0);
    A_AdvancedBuildingtype4(0,0,0);
    A_AdvancedBuildingtype5(0,0,0);
    A_AdvancedBuildingtype6(0,0,0);
    A_AdvancedBuildingtype7(0,0,0);
    A_AdvancedBuildingtype8(0,0,0, 0.196, 0.318, 0.553);
    A_GroundLine();
    A_Details1(0.008, 0.647, 0.949);
    A_Details2(0.008, 0.647, 0.949,  0.196, 0.318, 0.553, 0.0,0.0,0.0);
glColor3ub(255,255,255);
    if(text1){I_AnimatedTextAdder("A century later, New Beginnings had transformed into a thriving civilization, a testament to humanity's resilience.                 ", -15.0, 10.0);
    glutTimerFunc(2000,I_Timer,0);}

    if(text2){I_AnimatedTextAdder("The settlers, descendants of the Earth's refugees, had learned from past mistakes. Harmonizing with the planet,                     ",-15.0,10);
    glutTimerFunc(2000,I_Timer,0);}

    if(text3){I_AnimatedTextAdder("They cultivated sustainable practices, constructing cities that blended seamlessly with natural beauty.                               ",-15.0,10);
    glutTimerFunc(2000,I_Timer,0);}

    if(text4){I_AnimatedTextAdder("The legacy of a once-dying Earth had become a distant echo, replaced by the success story of a civilization reborn on a distant planet.",-15.0, 10);
    glutTimerFunc(2000,I_Timer,0);}

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
    }
    else
        {
        glClearColor(0.859, 0.788, 0.4, 1.0); // Day scene

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-25.0, 25.0, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    A_GradientEffect(27,139,185, 204,235,237 );
    A_SunMoon(1.0f, 0.8f, 0.0f, -20,17);
    A_FlyingObject1(0,0,0);
    A_FlyingObject2(0,0,0);
    A_FlyingObject3(0,0,0);
    A_FlyingObject4(0,0,0);
    A_AdvancedBuildingtype9(0,0,0);
    A_AdvancedBuildingtype1(0.133, 0.749, 0.651);
    A_AdvancedBuildingtype2(0.196, 0.341, 0.702);
    A_AdvancedBuildingtype3(0.588, 0.004, 0.004);
    A_AdvancedBuildingtype4(0.247, 0.506, 0.722);
    A_AdvancedBuildingtype5(0.055, 0.412, 0.031);
    A_AdvancedBuildingtype6(0.196, 0.341, 0.702);
    A_AdvancedBuildingtype7(0.196, 0.341, 0.702);
    A_AdvancedBuildingtype8(0.376, 0.102, 0.38, 0.596, 0.812, 0.871);
    A_GroundLine();
    A_Details1(1.0,1.0,1.0);
    A_Details2(1.0,1.0,1.0,  0.596, 0.812, 0.871,  0.0,0.0,0.0);
    A_Cloud();
    glColor3ub(255,255,255);

    if(text1){I_AnimatedTextAdder("A century later, New Beginnings had transformed into a thriving civilization, a testament to humanity's resilience.                 ", -15.0, 10.0);
    glutTimerFunc(2000,I_Timer,0);}

    if(text2){I_AnimatedTextAdder("The settlers, descendants of the Earth's refugees, had learned from past mistakes. Harmonizing with the planet,                     ",-15.0,10);
    glutTimerFunc(2000,I_Timer,0);}

    if(text3){I_AnimatedTextAdder("They cultivated sustainable practices, constructing cities that blended seamlessly with natural beauty.                               ",-15.0,10);
    glutTimerFunc(2000,I_Timer,0);}

    if(text4){I_AnimatedTextAdder("The legacy of a once-dying Earth had become a distant echo, replaced by the success story of a civilization reborn on a distant planet.",-15.0,10);
    glutTimerFunc(2000,I_Timer,0);}

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
    }

}
void keyboard(unsigned char key, int x, int y) {
    //
    switch (key) {
        case 'd':
            dayBackground = false;

            break;
        case 'n':
            dayBackground = true;

            break;
        case 'z':
            liftUp = true;
            break;
        case 'x':
            liftUp = false;
            FlyingObject1PositionY = -9.0;
            FlyingObject1PositionX = -15.0;
            break;
        case 'c':
            liftUpObject2 = true;
            break;
        case 'v':
            liftUpObject2 = false;
            FlyingObject2PositionY = 0.0;
            FlyingObject2PositionX = -15.0;
            break;

    }
    glutPostRedisplay();
}


void display(int value) {
    glutPostRedisplay();
    glutTimerFunc(200, display, 0);
    glutTimerFunc(180,MoveStars,0);
    glutTimerFunc(10,MoveClouds,0);
    glutTimerFunc(10, MoveFlyingObject, 0);
    glutTimerFunc(10, MoveFlyingObject1, 0);
    glutTimerFunc(10, MoveFlyingObject2, 0);

}

float RocketPositionX = -25.4f;
float RocketPositionYS = -21.5f;
 float RocketSizeS=.5;
 float RocketAngleS=-60;
bool RocketMoving = true;
bool I_keyPressed = true;
bool topViewScene=false,enteringScene=true,landingScene2=false,campingScene=false;

float targetBackgroundColor = 0.0;
float currentBackgroundColor = 1.0;
float morphingSpeed = 0.002;







class TextureInfo {
public:
    int imageWidth;
    int imageHeight;
    GLubyte* imageData;
    GLuint textureID;

    TextureInfo(const char* filename) {
        FILE* file = fopen(filename, "rb");
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            exit(1);
        }

        fseek(file, 18, SEEK_SET);
        fread(&imageWidth, sizeof(int), 1, file);
        fread(&imageHeight, sizeof(int), 1, file);

        int imageSize = imageWidth * imageHeight * 3;

        imageData = new GLubyte[imageSize];

        fseek(file, 54, SEEK_SET); // Skip the header
        fread(imageData, sizeof(GLubyte), imageSize, file);

        for (int i = 0; i < imageSize; i += 3) {
            GLubyte temp = imageData[i];
            imageData[i] = imageData[i + 2];
            imageData[i + 2] = temp;
        }

        fclose(file);

        glEnable(GL_TEXTURE_2D);
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
};
std::vector<TextureInfo> textures;
void loadImageAndStore(const char* filename) {
 textures.push_back(TextureInfo(filename));
 }

void I_MorphEffect(){
    currentBackgroundColor += morphingSpeed * (targetBackgroundColor - currentBackgroundColor);
    glClearColor(currentBackgroundColor, currentBackgroundColor, currentBackgroundColor, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    if (fabs(targetBackgroundColor - currentBackgroundColor) < 0.01) {
        // Morphing is complete, set the flag to false
        //landingScene = false;
    }
}


struct Star {
    float x, y, size;
};

void drawStaticStars(int numStars) {
    static std::vector<Star> stars;

    if (stars.empty()) {
        for (int i = 0; i < numStars; ++i) {
            Star star;
            star.x = (rand() % 3200 - 1600) / 100.0 * 25 / 16;
            star.y = (rand() % 1800 - 900) / 100.0 * 20 / 9;
            //star.z = (rand() % 1800 - 900) / 100.0 * 20 / 9;
            star.size = (rand() % 100 + 1) / 1000.0;

            stars.push_back(star);
        }
    }

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);

    for (std::vector<Star>::const_iterator it = stars.begin(); it != stars.end(); ++it) {
        const Star& star = *it;
        glPointSize(star.size);
        glVertex2d(star.x, star.y);
    }

    glEnd();
}


void IbackgroundEntering(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);

    glColor3ub(231,209,173);
    glVertex2d(-25*25/16,  20.0);

    glColor3ub(246,249,241);
    glVertex2d(-25*25/16, -0.0);

    glColor3ub(37,24,19);
    glVertex2d(-25*25/16, -20.0);


    glColor3ub(14,5,14);
    glVertex2d(25*25/16, -20);

    glColor3ub(28,28,49);
    glVertex2d(25*25/16, 20);

     glColor3ub(11,0,0);  // Light PINK
    glVertex2d(16*25/16,  9*20/9);
    glEnd();



}
float box1X=0.09;
float box1Speed=0.02;
void IdrawRunningBg() {
  //gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    printf("x");
    glColor3f(1.0, 1.0, 1.0); // Set color to red
    glPushMatrix();
    glTranslatef(0.0f,-box1X,  0.0f);

    ApplyTexture(-25, -20, 25, -20, 25, 20*4.5, -25, 20*4.5, textures[8].textureID);
   ApplyTexture(-25, 20*4.5, 25, 20*4.5, 25, 20*4.5*3, -25, 20*4.5*3, textures[8].textureID);
    ApplyTexture(-25, 20*4.5*3, 25, 20*4.5*3, 25, 20*4.5*5, -25, 20*4.5*5, textures[8].textureID);

    ApplyTexture(-25, 20*4.5*5, 25, 20*4.5*5, 25, 20*4.5*7, -25, 20*4.5*7, textures[8].textureID); // Fourth quadrilateral with a different texture

    glPopMatrix();



}
void IDrawCampingScene() {

   glClearColor(0.43921f, 0.756862f, 0.9803f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_POLYGON);
    glColor3ub(91,114,86);
    glVertex2d(-25.148447971377, 3.6018470641686);
    glColor3ub(64,93,32);
    glVertex2d(25.4748057155344, 3.746256366846);
    glColor3ub(29,64,40);
    glVertex2d(30.6309386049574, -22.1507337901415);
    glColor3ub(48,86,47);
    glVertex2d(-30.5800750399514, -23.6663419554707);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(225,224,163);
    glVertex2d(-24.6113176896744, -3.552588877938);
    glColor3ub(225,224,163);
    glVertex2d(-22, -2);
    glColor3ub(225,224,163);
    glVertex2d(-17.6894581890231, -0.7171283595988);
    glColor3ub(225,224,163);
    glVertex2d(-11.8517453571485, -0.5086386156033);
    glColor3ub(119,122,93);
    glVertex2d(-4.9715838052964, -0.4669406668041);
    glColor3ub(119,122,93);
    glVertex2d(1.7417859513594, -0.0499611788131);
    glColor3ub(119,122,93);
    glVertex2d(7.5794987832339, -0.3001488716077);
    glColor3ub(119,122,93);
    glVertex2d(13.0846546072026, -0.165684502391);
    glColor3ub(119,122,93);
    glVertex2d(17.7863260715131, -1.11212486209);
    glColor3ub(103,104,94);
    glVertex2d(24.4314059582957, -1.9690197516277);
    glColor3ub(103,104,94);
    glVertex2d(26.5444714478272, -3.6350906183739);
    glColor3ub(103,104,94);
    glVertex2d(29.5960157491609, -11.5168970985674);
    glColor3ub(103,104,94);
    glVertex2d(21.5900095797329, -17.0627242888486);
    glColor3ub(152,141,77);
    glVertex2d(10, -18);
    glColor3ub(152,141,77);
    glVertex2d(0.6993372313818, -18.0217771112281);
    glColor3ub(152,141,77);
    glVertex2d(-9.5166602243987, -17.7715894184334);
    glColor3ub(152,141,77);
    glVertex2d(-18.7736048577998, -16.3121612104647);
    glColor3ub(152,141,77);
    glVertex2d(-23.9858484576878, -15.0612227464915);
    glColor3ub(140,63,0);
    glVertex2d(-26, -14);
    glColor3ub(140,63,0);
    glVertex2d(-28, -12);
    glColor3ub(140,63,0);
    glVertex2d(-28.7394146207857, -8.6814365802282);
    glEnd();





        glBegin(GL_POLYGON);
    glColor3ub(72,146,131);
    glVertex2d(-16, 4);
    glVertex2d(-6.9842340837977, 18.286955837981);
    glVertex2d(-6.1522844912809, 18.6078879417721);
    glVertex2d(-5.1148272821353, 18.6770517557152);
    glVertex2d(-3.7142600497886, 19.0920346393735);
    glVertex2d(-2.5730571197284, 19.6453451509178);
    glVertex2d(-0.3993713806605, 3.7930118961569);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(72,146,131);
    glVertex2d(10.77,3.6370);
    glVertex2d(2.2132119632947, 18.6566111404697);
    glVertex2d(1.4373539405569, 18.9489634388927);
    glVertex2d(0.7733447406625, 19.2863172339758);
    glVertex2d(-0.2830268924704, 19.1850941414651);
    glVertex2d(-1.1713281069093, 19.3087816523363);
    glVertex2d(-2.0596293213482, 19.3650032481869);
    glVertex2d(-2.5730571197284, 19.6453451509178);
    glVertex2d(-0.3993713806605, 3.7930118961569);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(12,43,41);
    glVertex2d(25.2440332912297, 3.0503935);
    glVertex2d(21.4735312159991, 9.3279058033997);
    glVertex2d(20, 12);
    glVertex2d(18.2839677864446, 13.4305301180238);
    glVertex2d(16.6842804681846, 13.9637592241105);
    glVertex2d(15.2691724558777, 13.7791799181574);
    glVertex2d(12.9837120927482, 14.1797608576231);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(12,43,41);
    glVertex2d(12.9837120927482, 14.1797608576231);
    glVertex2d(11.4994286638799, 13.8793701636854);
    glVertex2d(9.1139731531987, 15.6993843681312);
    glVertex2d(8.1997986779767, 15.9093024056896);
    glVertex2d(7.030161362078, 15.5674084210423);
    glVertex2d(6.0044794081361, 15.4054586388409);
    glVertex2d(4.9787974541942, 15.2435088566395);
    glVertex2d(3.9711099204969, 15.8553191449558);
    glVertex2d(3.1310333037939, 16.5299376714628);
    glVertex2d(1.5441692656297, 16.0340426595365);
    glVertex2d(2.7048580281099, 3.6151828673984);
    glEnd();

                     glBegin(GL_POLYGON);
    glColor3ub(12,43,41);
    glVertex2d(12.9837120927482, 14.1797608576231);
    glVertex2d(2.7048580281099, 3.6151828673984);
    glVertex2d(25.1738972245144, 3.676031194194);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(12,43,41);
    glVertex2d(1.5441692656297, 16.0340426595365);
    glVertex2d(0.6014526593714, 15.8562726625679);
    glVertex2d(-1, 16);
    glVertex2d(-2.0952660274104, 15.4641798220053);
    glVertex2d(-3.0715146030192, 15.816714029864);
    glVertex2d(-4.1969122665683, 16.0878941897554);
    glVertex2d(-5.5438270010473, 16.7162684463941);
    glVertex2d(-7.4089881929823, 16.5470131224819);
    glVertex2d(2.7048580281099, 3.6151828673984);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(12,43,41);
    glVertex2d(-7.4089881929823, 16.5470131224819);
    glVertex2d(-9.1650193078812, 15.3887666896209);
    glVertex2d(-10.6576093609921, 15.0156191763432);
    glVertex2d(-12, 14);
    glVertex2d(-13.6846470831565, 13.1103588149074);
    glVertex2d(-14.7650418737314, 12.5101394868102);
    glVertex2d(-16.430650509201, 11.5797995282595);
    glVertex2d(-19.1705298058992, 10.436817661138);
    glVertex2d(-28.384460172789, 3.6056955073634);
    glVertex2d(2.7048580281099, 3.6151828673984);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(9,25,15);
    glVertex2d(-10.7573506011148, 3.617259168018);
    glVertex2d(-7.6886678010422, 5.4184425506694);
    glVertex2d(-6, 6);
    glVertex2d(-4.3753798502392, 6.2856789941682);
    glVertex2d(-3.0411699371642, 7.3752837565129);
    glVertex2d(-1.5513022008971, 8.175809704358);
    glVertex2d(0, 8);
    glVertex2d(1.2283017846759, 8.2647570318963);
    glVertex2d(3.2073798224039, 8.5315990145113);
    glVertex2d(16.4, 3.5);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(9,25,15);


    glVertex2d(7.3879042167057, 9.0652829797414);
    glVertex2d(8.2773774920891, 8.7539673333572);
    glVertex2d(10.0118503790866, 9.1542303072797);
    glVertex2d(11.1014551414312, 8.9985724840876);
    glVertex2d(12.5913228776984, 9.6879142725098);
    glVertex2d(13.3483900700621, 10.349237575109);
    glVertex2d(14, 10);
    glVertex2d(16.4, 3.5);glVertex2d(3.2073798224039, 8.5315990145113);
     glVertex2d(4.9863263731706, 8.6205463420497);glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(9,25,15);
    glVertex2d(14, 10);
    glVertex2d(14.8901756637622, 10.409975278567);
    glVertex2d(15.7438060008123, 10.349237575109);
    glVertex2d(16.2861643247557, 10.5300236830901);
    glVertex2d(17.0997018106709, 10.349237575109);
    glVertex2d(16.4, 3.5);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(9,25,15);
    glVertex2d(17.0997018106709, 10.349237575109);
    glVertex2d(18.1618201950601, 10.8689976355548);
    glVertex2d(19.4499212144258, 10.981988953043);
    glVertex2d(20.9640048687679, 11.6599368579724);
    glVertex2d(22.0713197801524, 12.5864656613758);
    glVertex2d(23.1334381645416, 13.400003147291);
    glVertex2d(25.0806688555158, 13.7701506229428);
    glVertex2d(25.0086445768901, 3.4663903493999);
    glVertex2d(16.4, 3.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(188,141,99);
    glVertex2d(6.2139388961163, -2.6693233640695);
    glVertex2d(5.7683827469791, -2.9445198091249);
    glVertex2d(5.5587092650322, -3.4162851435054);
    glVertex2d(4.6413877815144, -8.8809002667469);
    glVertex2d(5.3621403757069, -9.038155378207);
    glVertex2d(5.978056228926, -5.7357980375432);
    glVertex2d(6.6988088231185, -2.6693233640695);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(189,130,80);
    glVertex2d(-20.7016050041176, -0.9069131994594);
    glVertex2d(-20.78924,0.992946);
    glVertex2d(2.517001223613, -0.0920504156319);
    glVertex2d(2.5529320182239, -2.1640595715276);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(132,104,84);
    glVertex2d(11.1411106929983, -3.1756826717599);
    glVertex2d(10.4185337391448, -10.5888335411791);
    glVertex2d(17.84197283684, -12.7157310539493);
    glVertex2d(19.3738157231999, -3.5078961064106);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(188,141,99);
    glVertex2d(6.6988088231185, -2.6693233640695);
    glVertex2d(12.5425880385251, -3.6255534389784);
    glVertex2d(11.8519230118269, -4.028441371219);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(188,141,99);
    glVertex2d(6.6988088231185, -2.6693233640695);
    glVertex2d(11.8519230118269, -4.028441371219);
    glVertex2d(11.4490350795863, -4.8457283194786);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(188,141,99);
    glVertex2d(6.6988088231185, -2.6693233640695);
    glVertex2d(11.4490350795863, -4.8457283194786);
    glVertex2d(11.1842801526853, -6.8716790644601);
    glVertex2d(5.978056228926, -5.7357980375432);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(188,141,99);
    glVertex2d(7.23107,-6.00917);
    glVertex2d(11.1842801526853, -6.8716790644601);
    glVertex2d(10.4185337391448, -10.5888335411791);
    glVertex2d(6.6032632214037, -9.5360348369911);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(167,122,100);
    glVertex2d(6.6988088231185, -2.6693233640695);
    glVertex2d(12.5425880385251, -3.6255534389784);
    glVertex2d(12.6525224927116, -2.4177185697622);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,77,53);
    glVertex2d(7.7699563899958, -2.5334690592662);
    glVertex2d(8.8346786649371, -2.9575027315827);
    glVertex2d(8.0119801407769, -2.7860155818205);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,77,53);
    glVertex2d(7.7699563899958, -2.5334690592662);
    glVertex2d(8.8346786649371, -2.9575027315827);
    glVertex2d(8.7598976559477, -2.5088166776464);
    glVertex2d(7.8467821777617, -2.331703761619);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,77,53);
    glVertex2d(8.7598976559477, -2.5088166776464);
    glVertex2d(10.2122235673729, -2.5678543163223);
    glVertex2d(10.0469181790806, -2.8709141948581);
    glVertex2d(8.8346786649371, -2.9575027315827);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,77,53);
    glVertex2d(8.7598976559477, -2.5088166776464);
    glVertex2d(10.2122235673729, -2.5678543163223);
    glVertex2d(10, -2.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(158,109,72);
    glVertex2d(7.8467821777617, -2.331703761619);
    glVertex2d(8.7598976559477, -2.5088166776464);
    glVertex2d(10, -2.4);
    glVertex2d(9, -2.2);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(159,116,93);
    glVertex2d(12.6525224927116, -2.4177185697622);
    glVertex2d(12.5425880385251, -3.6255534389784);
    glVertex2d(19.0293221872068, -3.4594729752985);
    glEnd();


        glBegin(GL_POLYGON);
    glColor3ub(177,134,102);
    glVertex2d(12.9765141272435, -3.7548337005971);
    glVertex2d(12.4092808866323, -3.8939663822565);
    glVertex2d(12.0025853556281, -4.3541744831297);
    glVertex2d(11.852750159995, -5.0819454333478);
    glVertex2d(10.8930725652059, -10.6680848722918);
    glVertex2d(11.7979622440652, -10.9728898167497);
    glEnd();
   glBegin(GL_POLYGON);
    glColor3ub(137,104,83);
    glVertex2d(19, -6);
    glVertex2d(20.1011970605286, -6.1491889858596);
    glVertex2d(19.8961559153878, -13.1760879557126);
    glVertex2d(17.84197283684, -12.7157310539493);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(177,134,102);
    glVertex2d(20.3720912459854, -5.0506914340759);
    glVertex2d(19.6702303916857, -5.4444182547806);
    glVertex2d(19.44737,-5.754830);
    glVertex2d(19.1909107838713, -6.1120419942364);
    glVertex2d(18.8314210780104, -8.5257585907305);
    glVertex2d(12.1551836834522, -7.0706812098653);
    glVertex2d(12.9765141272435, -3.7548337005971);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(187,142,118);
    glVertex2d(12.9765141272435, -3.7548337005971);
    glVertex2d(20.3720912459854, -5.0506914340759);
    glVertex2d(27.2804633729392, -4.7098090417586);
    glVertex2d(19.3738157231999, -3.5078961064106);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(90,60,39);
    glVertex2d(15.7317664808853, -4.1214383721879);
    glVertex2d(15.6591081,-3.6512848);
    glVertex2d(14.5394846751152, -3.5048972102688);
    glVertex2d(14.5848185840799, -3.8403681366072);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(90,60,39);
    glVertex2d(15.7317664808853, -4.1214383721879);
    glVertex2d(15.6591081,-3.6512848);
    glVertex2d(17.1235174860998, -3.5230307738547);
    glVertex2d(17.1144507043069, -4.0353039451551);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(146,113,103);
    glVertex2d(14.5394846751152, -3.5048972102688);
    glVertex2d(15.6591081,-3.6512848);
    glVertex2d(17.1235174860998, -3.5230307738547);
    glVertex2d(15.9493692439156, -3.3280949653067);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(90,60,39);
    glVertex2d(19.8374496992718, -4.2201941346968);
    glVertex2d(20, -4.4);
    glVertex2d(20.6323617440595, -4.4189221458938);
    glVertex2d(20.6678488889161, -3.26913865254);
    glVertex2d(19.8268035558148, -3.1981643628269);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(90,60,39);
    glVertex2d(20.6678488889161, -3.26913865254);
    glVertex2d(20.6323617440595, -4.4189221458938);
    glVertex2d(21.6047095131303, -4.333752998238);
    glVertex2d(21.5656736537881, -3.2301027931978);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(146,113,103);
    glVertex2d(19.8268035558148, -3.1981643628269);
    glVertex2d(20.6678488889161, -3.26913865254);
    glVertex2d(21.5656736537881, -3.2301027931978);
    glVertex2d(20.7352744641437, -3.0597644978861);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(146,113,103);
    glVertex2d(19.8268035558148, -3.1981643628269);
    glVertex2d(20.6678488889161, -3.26913865254);
    glVertex2d(21.5656736537881, -3.2301027931978);
    glVertex2d(20.7352744641437, -3.0597644978861);
    glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(137,104,83);
    glVertex2d(19.44737,-5.7548);
    glVertex2d(19.1909107838713, -6.1120419942364);
    glVertex2d(20.1011970605286, -6.1491889858596);
    glVertex2d(20.2434910013671, -5.7883722073047);
    glEnd();

       glBegin(GL_POLYGON);
    glColor3ub(137,104,83);
    glVertex2d(19.44737,-5.7548);
    glVertex2d(20.2434910013671, -5.7883722073047);
    glVertex2d(20.6894871862058, -5.5952289394625);
    glVertex2d(20.3720912459854, -5.0506914340759);
    glVertex2d(19.6702303916857, -5.4444182547806);
    glEnd();

           glBegin(GL_POLYGON);
    glColor3ub(137,104,83);
    glVertex2d(20.3720912459854, -5.0506914340759);
    glVertex2d(21.7731508653816, -4.960018194566);
    glVertex2d(22, -5.5);
    glVertex2d(20.6894871862058, -5.5952289394625);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(21.7731508653816, -4.960018194566);
    glVertex2d(25.39,-4.8030);
    glVertex2d(25.4982029594767, -5.4021457964572);
    glVertex2d(22, -5.5);
    glEnd();

        glBegin(GL_POLYGON);
    glVertex2d(19.1654857227701, -6.0832105519796);
    glVertex2d(20.1011970605286, -6.1491889858596);
    glVertex2d(19.8961559153878, -13.1760879557126);
    glVertex2d(17.84197283684, -12.7157310539493);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(24.171820153803, -5.4072277229157);
    glVertex2d(25.4982029594767, -5.4021457964572);
    glVertex2d(27.3072590791008, -13.0302497384167);
    glVertex2d(19.8961559153878, -13.1760879557126);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(19.8961559153878, -13.1760879557126);
    glVertex2d(22, -5.5);
    glVertex2d(24.171820153803, -5.4072277229157);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(20.0775070579609, -5.5286642927952);
    glVertex2d(22, -5.5);
    glVertex2d(19.8961559153878, -13.1760879557126);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(177,134,102);
    glVertex2d(18.7383445291858, -8.2420414536911);
    glVertex2d(17.84197283684, -12.7157310539493);
    glVertex2d(13.3792773292907, -11.4361430055761);
    glVertex2d(14.0878095544229, -7.2060998704583);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(72,40,9);
    glVertex2d(22.4039602070821, -9.5728640706613);
    glVertex2d(22.6689816413779, -9.3144681722229);
    glVertex2d(23.6760630917021, -9.2747149570785);
    glVertex2d(23.8350759522796, -9.3807235307969);

       glVertex2d(23.8947057749961, -10.387804981121);
    glVertex2d(23.7555695219908, -10.5865710568429);
    glVertex2d(22.5099687808004, -10.6594519512742);
    glVertex2d(22.3244537767933, -10.454060339695);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(72,40,9);
    glVertex2d(11.7979622440652, -10.9728898167497);
    glVertex2d(13.3792773292907, -11.4361430055761);
    glVertex2d(14.04,-7.4818);
    glVertex2d(12.4254,-7.129);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(72,40,9);
    glVertex2d(5.978056228926, -5.7357980375432);
    glVertex2d(7.2558616177225, -5.9630152365642);
    glVertex2d(6.6032632214037, -9.5360348369911);
    glVertex2d(5.3621403757069, -9.038155378207);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(86,56,32);
    glVertex2d(9.6177912006374, -7.7397380974597);
    glVertex2d(9.8512490394617, -8.0607426258431);
    glVertex2d(9.4229660313687, -10.3090795919167);
    glVertex2d(7.3231413141558, -9.7146976534017);
    glVertex2d(7.7793107198959, -7.3409142894682);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(171,131,105);
    glVertex2d(-3.5190781719902, -4.3779381293996);
    glVertex2d(-3.4211595452892, -7.9533373972708);
    glVertex2d(0.7128665538956, -7.6007115820515);
    glVertex2d(0.8267494185577, -4.1600622087045);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(171,131,105);
    glVertex2d(0.8267494185577, -4.1600622087045);
    glVertex2d(0.7659179591345, -3.9909579669784);
    glVertex2d(0.6724810418841, -3.788511312936);
    glVertex2d(0.371406530744, -3.6795015761439);
    glVertex2d(-3.56638,-3.778235);
    glVertex2d(-3.5473441465867, -4.417968058135);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(235,182,146);
    glVertex2d(0.371406530744, -3.6795015761439);
    glVertex2d(-3.56638,-3.778235);
    glVertex2d(-3.6045269,-2.83467);
    glVertex2d(-2.4602598231985, -2.8924065214086);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(138,89,48);
    glVertex2d(-3.5826225911601, -2.7615457656519);
    glVertex2d(-3.5724760666171, -3.0788991205883);
    glVertex2d(-3.1246653261834, -3.2162277476547);
    glVertex2d(-3.0977966817574, -2.8908186096061);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(138,89,48);
    glVertex2d(-3.0977966817574, -2.8908186096061);
    glVertex2d(-3.1246653261834, -3.2162277476547);
    glVertex2d(-1.9728513342711, -3.1659004877738);
    glVertex2d(-2.0453704447298, -2.8194202933599);
    glEnd();

                    glBegin(GL_POLYGON);
    glColor3ub(205,151,112);
    glVertex2d(-3.5826225911601, -2.7615457656519);
    glVertex2d(-3.0977966817574, -2.8908186096061);
    glVertex2d(-2.0453704447298, -2.8194202933599);
    glVertex2d(-2.5611359647771, -2.6973922741298);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(185,133,100);
    glVertex2d(-7.4420140296614, -7.9533373972708);
    glVertex2d(-3.4211595452892, -7.9533373972708);
    glVertex2d(-3.5934072967005, -3.0013816625678);
    glVertex2d(-7.5, -3);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(185,133,100);
    glVertex2d(-7.5, -3);
    glVertex2d(-7.4735019526799, -2.7340137955171);
    glVertex2d(-7.2583034255415, -2.5775057757801);
    glVertex2d(-3.7694788189046, -2.5318576033568);
    glVertex2d(-3.6129707991677, -2.6883656230938);
    glVertex2d(-3.56638,-3.778235);
    glVertex2d(-3.6045269,-2.83467);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(254,227,185);
    glVertex2d(-7.4735019526799, -2.7340137955171);
    glVertex2d(-7.5, -3);
    glVertex2d(-9.1817306944585, -2.4712341333278);
    glVertex2d(-9.1372557460498, -2.2407730370281);
    glEnd();


        glBegin(GL_POLYGON);
    glColor3ub(254,227,185);
    glVertex2d(-7.4735019526799, -2.7340137955171);
    glVertex2d(-9.1372557460498, -2.2407730370281);
    glVertex2d(-9.0563922034885, -2.1356504316983);
    glVertex2d(-8.8865787641097, -2.0830891290335);
    glVertex2d(-7.2583034255415, -2.5775057757801);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(185,133,100);
    glVertex2d(-9.1817306944585, -2.4712341333278);
    glVertex2d(-7.5, -3);
    glVertex2d(-7.4420140296614, -7.9533373972708);
    glVertex2d(-9.2625923234377, -7.5271107132509);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(203,163,139);
    glVertex2d(-7.2583034255415, -2.5775057757801);
    glVertex2d(-8.8865787641097, -2.0830891290335);
    glVertex2d(-5.6721161705689, -1.8982477372681);
    glVertex2d(-3.7694788189046, -2.5318576033568);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(185,133,100);
    glVertex2d(-9.2625923234377, -7.5271107132509);
    glVertex2d(-10.7138106910728, -6.719052222528);
    glVertex2d(-10.700025,-3.9075);
    glVertex2d(-9.21,-4.40);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(253,219,170);
    glVertex2d(-8.8, -4.4);
    glVertex2d(-8.810145768441, -4.5421420674758);
    glVertex2d(-10.8056795492328, -3.8721536137783);
    glVertex2d(-10.8125454135522, -3.6738007769272);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(253,219,170);
    glVertex2d(-10.8125454135522, -3.6738007769272);
    glVertex2d(-10.6962469458371, -3.436896490841);
    glVertex2d(-8.6287186309022, -4.1346872971315);
    glVertex2d(-8.8, -4.4);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(253,219,170);
    glVertex2d(-10.6962469458371, -3.436896490841);
    glVertex2d(-8.6287186309022, -4.1346872971315);
    glVertex2d(-8.4219657994088, -4.0313108813847);
    glVertex2d(-10.5110308676242, -3.3550568283748);
    glEnd();

                    glBegin(GL_POLYGON);
    glColor3ub(253,219,170);
    glVertex2d(-8.4219657994088, -4.0313108813847);
    glVertex2d(-10.5110308676242, -3.3550568283748);
    glVertex2d(-10.3128927374429, -3.286139217877);
    glEnd();

                    glBegin(GL_POLYGON);
    glColor3ub(253,219,170);
    glVertex2d(-8.4219657994088, -4.0313108813847);
    glVertex2d(-10.3128927374429, -3.286139217877);
    glVertex2d(-10.0286075941394, -3.2947539191892);
    glVertex2d(-7.9352351752678, -3.9925447254797);
    glEnd();

                        glBegin(GL_POLYGON);
    glColor3ub(171,124,92);
    glVertex2d(-7.5830368403527, -4.499709338787);
    glVertex2d(-7.6, -4.6);
    glVertex2d(-8.810145768441, -4.5421420674758);
    glVertex2d(-8.8, -4.4);
    glVertex2d(-8.6287186309022, -4.1346872971315);
    glVertex2d(-8.4219657994088, -4.0313108813847);
    glVertex2d(-7.9352351752678, -3.9925447254797);
    glVertex2d(-7.7400618210344, -4.0831663020821);
    glVertex2d(-7.6343426840617, -4.181149892447);
    glVertex2d(-7.5827723733433, -4.3539104333537);
    glEnd();

                        glBegin(GL_POLYGON);
    glColor3ub(125,78,41);
    glVertex2d(-6.5, -3.5);
    glVertex2d(-4.4880542849211, -3.4048062816963);
    glVertex2d(-4.4474210772579, -4.7964936441591);
    glVertex2d(-6.4790814604155, -4.8726809085275);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(123,75,41);
    glVertex2d(-7.8986137401501, -4.8509775322012);
    glVertex2d(-7.5885039646801, -4.8509775322012);
    glVertex2d(-7.6, -5.4);
    glVertex2d(-7.918054254616, -5.3982506713649);
    glEnd();

    glBegin(GL_POLYGON);
            glColor3ub(123,75,41);
    glVertex2d(-1.6499367682535, -4.7344767853314);
    glVertex2d(-1.5133087855427, -4.6185500121223);
    glVertex2d(-0.8, -4.6);
    glVertex2d(-0.6190165350725, -4.7054950920291);
    glVertex2d(-0.6190165350725, -6.3574516102587);
    glVertex2d(-0.7556445177833, -6.5230612862717);
    glVertex2d(-1.4470649151375, -6.5810246728762);
    glVertex2d(-1.6375160425525, -6.5065003186704);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(123,75,41);
    glVertex2d(-2.9265219961073, -4.835206608545);
    glVertex2d(-2.9190355844294, -5.5426725121035);
    glVertex2d(-2.2677177684549, -5.5239564829089);
    glVertex2d(-2.2864337976496, -4.8090041676725);
    glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(176,118,71);
    glVertex2d(-13.1912656954457, -2.367263363179);
    glVertex2d(-13.2040748999648, -2.8027763168303);
    glVertex2d(-20.1295698659171, -3.1927845714273);
    glVertex2d(-20.1402591470883, -2.7835625100516);
    glEnd();

            glBegin(GL_POLYGON);
        glColor3ub(176,118,71);
    glVertex2d(-20.1295698659171, -3.1927845714273);
    glVertex2d(-20.1402591470883, -2.7835625100516);
    glVertex2d(-22.3690607334216, -2.5145692151493);
    glVertex2d(-22.3459465238668, -2.9626223800249);
    glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(187,129,80);
    glVertex2d(-20.1295698659171, -3.1927845714273);
    glVertex2d(-20.0784227122721, -6.0570251755469);
    glVertex2d(-13.5315870457129, -5.3835876525545);
    glVertex2d(-13.6424058786104, -2.8432790215199);
    glEnd();

                    glBegin(GL_POLYGON);
        glColor3ub(187,129,80);
    glVertex2d(-20.1295698659171, -3.1927845714273);
    glVertex2d(-20.0784227122721, -6.0570251755469);
    glVertex2d(-22.3885691519043, -5.7416177280695);
    glVertex2d(-22.3459465238668, -2.9626223800249);
    glEnd();

                        glBegin(GL_POLYGON);
        glColor3ub(147,91,44);
    glVertex2d(-16.6088057492155, -3.528386273191);
    glVertex2d(-16.6, -4.6);
    glVertex2d(-14.4, -4.4);
    glVertex2d(-14.446892952009, -3.3440013864356);
    glEnd();

                            glBegin(GL_POLYGON);
        glColor3ub(147,91,44);
    glVertex2d(-18.1392003092849, -3.6574556939197);
    glVertex2d(-18.1023233319339, -4.4042144852789);
    glVertex2d(-19.1210498312572, -4.5378935281765);
    glVertex2d(-19.1440979421016, -3.8003539811551);
    glEnd();


                            glBegin(GL_POLYGON);
        glColor3ub(147,91,44);
    glVertex2d(-20.9239106402476, -3.8241781172173);
    glVertex2d(-20.5578518095069, -3.8982124874795);
    glVertex2d(-20.5290606655161, -4.5974259843998);
    glVertex2d(-20.903345537397, -4.535730675848);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(251,199,153);
    glVertex2d(-20.1402591470883, -2.7835625100516);
    glVertex2d(-22.3690607334216, -2.5145692151493);
    glVertex2d(-15.4976070690386, -2.0737168926443);
    glVertex2d(-13.1912656954457, -2.367263363179);
    glEnd();

       glBegin(GL_POLYGON);
    glColor3ub(113,79,52);
    glVertex2d(-16.08590132531, -1.6887905998732);
    glVertex2d(-16.0436661552939, -2.4959516268481);
    glVertex2d(-17.0009966756595, -2.4631020501689);
    glVertex2d(-17.066695829018, -1.6606338198624);
    glEnd();

           glBegin(GL_POLYGON);
    glColor3ub(113,79,52);
    glVertex2d(-16.08590132531, -1.6887905998732);
    glVertex2d(-16.0436661552939, -2.4959516268481);
    glVertex2d(-15.809026321871, -2.3270109467836);
    glVertex2d(-15.8747254752294, -1.6090130565094);
    glEnd();

               glBegin(GL_POLYGON);
    glColor3ub(252,200,160);
    glVertex2d(-17.066695829018, -1.6606338198624);
    glVertex2d(-16.08590132531, -1.6887905998732);
    glVertex2d(-15.8747254752294, -1.6090130565094);
    glVertex2d(-16.372161922086, -1.5761634798302);
    glEnd();

                   glBegin(GL_POLYGON);
    glColor3ub(136,90,59);
    glVertex2d(-18.9555888864733, -7.8003829186237);
    glVertex2d(-26.3582119999731, -8.9679890879454);
    glVertex2d(-25.2489861391175, -15.1329496619642);
    glVertex2d(-18.8972085780072, -13.241427667663);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(149,111,83);
    glVertex2d(-21.1530582421499, -8.5098566990717);
    glVertex2d(-20.2169253820537, -8.4341002826477);
    glVertex2d(-20.1519913108331, -11.1992094821225);
    glVertex2d(-21.1097688613362, -11.5617580464372);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(108,61,29);
    glVertex2d(-22.6248971898155, -8.8832276085898);
    glVertex2d(-21.9588291641378, -8.7898979859298);
    glVertex2d(-21.9089062607229, -9.8039569615456);
    glVertex2d(-22.5761966364001, -9.8788833673048);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(136,90,59);
    glVertex2d(-23.280017l,-8.482468);
    glVertex2d(-26.3582119999731, -8.9679890879454);
    glVertex2d(-24.9898573507597, -6.7041643460911);
    glVertex2d(-23.3304731548784, -6.510735715664);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(109,65,30);
    glVertex2d(-24.1456001214578, -7.2436206733582);
    glVertex2d(-24.0655427034716, -7.3848984698045);
    glVertex2d(-24.0043223250115, -8.9012801516612);
    glVertex2d(-24.1079260424055, -9.099069066686);
    glVertex2d(-25.2758224930281, -9.3204042811185);
    glVertex2d(-25.2758224930281, -7.4037355093307);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(227,172,131);
    glVertex2d(-18.9755054608495, -7.6312691454459);
    glVertex2d(-18.8638789527814, -7.4881726192091);
    glVertex2d(-18.8319995584147, -7.3561008425469);
    glVertex2d(-19, -7.2);
    glVertex2d(-19.3375156690873, -6.9826565085364);
    glVertex2d(-23.2939833503256, -7.5261475283266);
    glVertex2d(-23.2827713545403, -8.1988672754442);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(227,172,131);
    glVertex2d(-18.9755054608495, -7.6312691454459);
    glVertex2d(-23.2827713545403, -8.1988672754442);
    glVertex2d(-23.28001,-8.482468);
    glVertex2d(-18.9555888864733, -7.8003829186237);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(215,162,119);
    glVertex2d(-23.3304731548784, -6.510735715664);
    glVertex2d(-23.2939833503256, -7.5261475283266);
    glVertex2d(-19.3375156690873, -6.9826565085364);
    glEnd();
            glBegin(GL_POLYGON);
    glColor3ub(168,125,96);
    glVertex2d(-25.158351944532, -5.8221533559692);
    glVertex2d(-24.5057082598492, -5.9429272762663);
    glVertex2d(-25.4116704066166, -5.9955184122515);
    glEnd();
        glBegin(GL_POLYGON);
    glColor3ub(168,125,96);
    glVertex2d(-23.1024886468962, -6.4975827632804);
    glVertex2d(-23.2351150383951, -6.0123909344858);
    glVertex2d(-23.5135116552606, -5.7677393620888);
    glVertex2d(-25.4116704066166, -5.9955184122515);
    glVertex2d(-24.9898573507597, -6.7041643460911);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(136,85,45);
    glVertex2d(-25.158351944532, -5.8221533559692);
    glVertex2d(-24.5057082598492, -5.9429272762663);
    glVertex2d(-24.433708422749, -5.4575090196873);
    glVertex2d(-25.1397713414094, -5.2972513177545);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(136,85,45);
    glVertex2d(-24.433708422749, -5.4575090196873);
    glVertex2d(-24.5057082598492, -5.9429272762663);
    glVertex2d(-23.9668707692926, -5.8686048637758);
    glVertex2d(-23.8879032060214, -5.3320899486095);
    glEnd();

                    glBegin(GL_POLYGON);
    glColor3ub(201,140,94);
    glVertex2d(-25.1397713414094, -5.2972513177545);
    glVertex2d(-24.5753855215591, -5.2647352622899);
    glVertex2d(-23.8879032060214, -5.3320899486095);
    glVertex2d(-24.433708422749, -5.4575090196873);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(97,61,33);
    glVertex2d(-16.2, -10);
    glVertex2d(-16.1993185609765, -11.0419969187914);
    glVertex2d(-14.6242133444762, -11.1495126332283);
    glVertex2d(-14.6742150178319, -10.0796464575264);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(97,61,33);
    glVertex2d(-14.6742150178319, -10.0796464575264);
    glVertex2d(-14.6242133444762, -11.1495126332283);
    glVertex2d(-14.2479083439472, -10.8753475614143);
    glVertex2d(-14.341,-9.885);
    glEnd();

           glBegin(GL_POLYGON);
    glColor3ub(171,116,81);
    glVertex2d(-14.6742150178319, -10.0796464575264);
    glVertex2d(-15.8, -9.6);
    glVertex2d(-16.2, -10);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(97,61,33);
    glVertex2d(-15.7445254733455, -9.2233980931156);
    glVertex2d(-15.7162531216905, -9.8534676442858);
    glVertex2d(-14.6742150178319, -10.0796464575264);
    glVertex2d(-14.7105651842456, -9.4616936284941);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(97,61,33);
    glVertex2d(-14.7105651842456, -9.4616936284941);
    glVertex2d(-14.6742150178319, -10.0796464575264);
    glVertex2d(-14.2380130208679, -9.8251952926308);
    glVertex2d(-14.2420519282472, -9.2799427964257);
    glEnd();

                    glBegin(GL_POLYGON);
    glColor3ub(197,153,126);
    glVertex2d(-15.7445254733455, -9.2233980931156);
    glVertex2d(-14.7105651842456, -9.4616936284941);
    glVertex2d(-14.2420519282472, -9.2799427964257);
    glVertex2d(-15.2840900321057, -9.1183865012539);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(108,70,44);
    glVertex2d(-11.9696463922144, -5.8559689435809);
    glVertex2d(-11.9011863741911, -7.2373673942881);
    glVertex2d(-12.5018517035414, -7.0356514254764);
    glVertex2d(-12.5415084648426, -5.6750737981576);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(108,70,44);
    glVertex2d(-11.9696463922144, -5.8559689435809);
    glVertex2d(-11.9011863741911, -7.2373673942881);
    glVertex2d(-10.7491640634221, -7.0535817338152);
    glVertex2d(-10.8142515924144, -5.7392623981465);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(158,106,70);
    glVertex2d(-11.9696463922144, -5.8559689435809);
    glVertex2d(-12.5415084648426, -5.6750737981576);
    glVertex2d(-11.1702065559891, -5.482507998191);
    glVertex2d(-10.8142515924144, -5.7392623981465);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(108,70,44);
    glVertex2d(-7.3868483769918, -12.4484893475352);
    glVertex2d(-7.4, -11.8);
    glVertex2d(-6.6476175357424, -11.6438224065048);
    glVertex2d(-6.6, -12.2);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(108,70,44);
    glVertex2d(-8.1713032691293, -11.6009565674582);
    glVertex2d(-7.4, -11.8);
    glVertex2d(-7.3868483769918, -12.4484893475352);
    glVertex2d(-8.1444430248754, -12.2326156037834);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(158,106,70);
    glVertex2d(-8.1713032691293, -11.6009565674582);
    glVertex2d(-7.4, -11.8);
    glVertex2d(-6.6476175357424, -11.6438224065048);
    glVertex2d(-7.415305744124, -11.5074311004472);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(108,70,44);
    glVertex2d(-6.4633193678772, -12.2337951571155);
    glVertex2d(-5.5556284585693, -12.3238713542223);
    glVertex2d(-5.5324558958994, -12.9121900594715);
    glVertex2d(-6.4558663564154, -12.7998833818412);
    glEnd();

                    glBegin(GL_POLYGON);
    glColor3ub(108,70,44);
    glVertex2d(-5.5556284585693, -12.3238713542223);
    glVertex2d(-5.5324558958994, -12.9121900594715);
    glVertex2d(-5.2404585340606, -12.7899005660518);
    glVertex2d(-5.2853998672487, -12.2199372806375);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(158,106,70);
    glVertex2d(-6.4633193678772, -12.2337951571155);
    glVertex2d(-5.5556284585693, -12.3238713542223);
    glVertex2d(-5.2853998672487, -12.2199372806375);
    glVertex2d(-5.7704255439781, -12.0328559481847);
    glEnd();

                        glBegin(GL_POLYGON);
    glColor3ub(108,70,44);
    glVertex2d(-7.3379460717046, -8.6098339287707);
    glVertex2d(-6.1758981990975, -8.7679824558119);
    glVertex2d(-6.1758981990975, -9.8337660076113);
    glVertex2d(-7.3448220946194, -9.5862291826772);
    glEnd();

                            glBegin(GL_POLYGON);
    glColor3ub(108,70,44);
    glVertex2d(-6.1758981990975, -8.7679824558119);
    glVertex2d(-6.1758981990975, -9.8337660076113);
    glVertex2d(-4.986346234831, -9.6618654347404);
    glVertex2d(-4.9932222577458, -8.6579660891745);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(195,141,115);
    glVertex2d(-7.3379460717046, -8.6098339287707);
    glVertex2d(-6.1758981990975, -8.7679824558119);
    glVertex2d(-4.9932222577458, -8.6579660891745);
    glVertex2d(-6.3546747948832, -8.4516854017295);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(108,70,44);
    glVertex2d(-3.3582438209624, -8.7352077003967);
    glVertex2d(-3.361647387537, -9.3308318509526);
    glVertex2d(-2.4, -9.4);
    glVertex2d(-2.4290701460952, -8.776050499292);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(108,70,44);
    glVertex2d(-2.4290701460952, -8.776050499292);
    glVertex2d(-2.4, -9.4);
    glVertex2d(-2.163591953276, -9.2491462531621);
    glVertex2d(-2.1840133527236, -8.6262935700094);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(195,141,115);
    glVertex2d(-3.3582438209624, -8.7352077003967);
    glVertex2d(-2.4290701460952, -8.776050499292);
    glVertex2d(-2.1840133527236, -8.6262935700094);
    glVertex2d(-2.878340933943, -8.5752400713903);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(202,141,86);
    glVertex2d(-21.3559136752471, 1.0193270310316);
    glVertex2d(-21.4654592511933, 3.0094049940547);
    glVertex2d(-21.2684659326265, 3.2161074514782);
    glVertex2d(-20.9992947236884, 3.3040000911314);
    glVertex2d(-20.675190614967, 3.3424531209797);
    glVertex2d(2.3907643652133, 2.8919661460094);
    glVertex2d(2.517001223613, -0.0920504156319);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(202,141,86);
    glVertex2d(3.7800884235018, 2.8081276252507);
    glVertex2d(9.5050616981734, 2.8919661460094);
    glVertex2d(13.3706376800891, 0.3276605267222);
    glVertex2d(2.517001223613, -0.0920504156319);
    glVertex2d(2.3907643652133, 2.8919661460094);
    glVertex2d(2.3907643652133, 2.8919661460094);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(202,141,86);
    glVertex2d(14.0562956822219, 0.4965798386155);
    glVertex2d(14.1223757981138, 0.968562423445);
    glVertex2d(14.1281572714437, 1.3589189092773);
    glVertex2d(14.0922264768328, 1.873926965367);
    glVertex2d(13.8886186407043, 2.3769580899198);
    glVertex2d(13.613149215354, 2.7003352414179);
    glVertex2d(13.2658182007819, 2.9758046667682);
    glVertex2d(12.8346486654509, 3.1075509136749);
    glVertex2d(9.5050616981734, 2.8919661460094);
    glVertex2d(13.212401086127, 0.2792344620141);
    glVertex2d(13.3682607271696, 0.3191701764945);
    glVertex2d(13.724984014994, 0.4086204269158);
    glVertex2d(13.8305999733227, 0.4355632734282);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(170,117,73);
    glVertex2d(13.212401086127, 0.2792344620141);
    glVertex2d(13.2110635224671, -1.5303920710009);
    glVertex2d(2.5529320182239, -2.1640595715276);
    glVertex2d(2.517001223613, -0.0920504156319);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139,88,50);
    glVertex2d(13.3682607271696, 0.3191701764945);
    glVertex2d(13.3549384014291, -1.0754625035153);
    glVertex2d(13.7238714499391, -1.0852745526778);
    glVertex2d(13.724984014994, 0.4086204269158);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139,88,50);
    glVertex2d(13.7238714499391, -1.0852745526778);
    glVertex2d(13.724984014994, 0.4086204269158);
    glVertex2d(13.8305999733227, 0.4355632734282);
    glVertex2d(13.8278791710616, -1.0283646675353);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(148,99,59);
    glVertex2d(8.4814551009249, 0.0182800265774);
    glVertex2d(8.5005741260273, -1.5064622253452);
    glVertex2d(10.0157568653987, -1.3535100245254);
    glVertex2d(10.0205366216744, 0.0851966144361);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(162,115,77);
    glVertex2d(9.015737354768, -0.4397116602229);
    glVertex2d(9.5317082269563, -0.435063273987);
    glVertex2d(9.5572743512539, -0.9510341461752);
    glVertex2d(9.0436276721836, -0.9905454291806);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(150,100,63);
    glVertex2d(11.0261401781585, 0.1173404205064);
    glVertex2d(11.6830402175638, 0.1339009257015);
    glVertex2d(11.685800301763, -1.1550583953165);
    glVertex2d(11.0565011043495, -1.224060500296);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(162,115,77);
    glVertex2d(11.0997538663508, 0.0451760132257);
    glVertex2d(11.3084673604312, 0.0490410779308);
    glVertex2d(11.3200625545468, -1.091153010101);
    glVertex2d(11.1113490604664, -1.1220735277425);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(162,115,77);
    glVertex2d(11.3780385251247, 0.0374458838153);
    glVertex2d(11.5944821486155, 0.0451760132257);
    glVertex2d(11.6022122780259, -1.0640975571646);
    glVertex2d(11.405093978061, -1.0602324924594);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(162,115,77);
    glVertex2d(10.2865334528757, -0.2593252587217);
    glVertex2d(10.7144894198816, -0.2200632434001);
    glVertex2d(10.7144894198816, -0.9797832398739);
    glVertex2d(10.319906165899, -1.0700858751136);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(150,99,59);
    glVertex2d(7.9038335569688, -0.5957752625813);
    glVertex2d(8.2895905888474, -0.5695195483697);
    glVertex2d(8.3077676217632, -0.3493754830568);
    glVertex2d(7.9725023479838, -0.3554344940287);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(150,99,59);
    glVertex2d(8.2895905888474, -0.5695195483697);
    glVertex2d(7.9038335569688, -0.5957752625813);
    glVertex2d(7.9159515789126, -1.2036960300969);
    glVertex2d(8.3077676217632, -1.1734009752373);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(150,99,59);
    glVertex2d(6.808540404458, -0.1298924179668);
    glVertex2d(7.4968253081472, -0.0342972924544);
    glVertex2d(7.4968253081472, -1.5351407629989);
    glVertex2d(6.8276594295605, -1.6928727200944);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(172,121,82);
    glVertex2d(6.8710749058294, -0.1859059322077);
    glVertex2d(7.0993641672712, -0.1804049861488);
    glVertex2d(7.0911127481829, -1.5941481232702);
    glVertex2d(6.8903282170353, -1.6436566377997);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(185,125,73);
    glVertex2d(2.0270583097296, 1.2717945895703);
    glVertex2d(2.0329076978335, 0.3856122918398);
    glVertex2d(-16.4907887648019, 1.2886438505542);
    glVertex2d(-16.4639662777405, 2.1018976338297);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(1.239054488817, 1.1663303149887);
    glVertex2d(1.8734573604394, 1.1210158241585);
    glVertex2d(1.8915831567714, 0.537969375477);
    glVertex2d(1.4867737053553, 0.537969375477);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(1.0517545933856, 1.1814351452654);
    glVertex2d(0.8344995298169, 0.5877388197136);
    glVertex2d(1.3024947759792, 0.5712000020858);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(0.888622426397, 1.1753932131547);
    glVertex2d(0.6983015649103, 0.5953677305285);
    glVertex2d(0.3758499329812, 0.6039264525431);
    glVertex2d(0.08202448962, 1.1995609415975);
    glEnd();

                    glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(-0.0992334737007, 1.2025819076528);
    glVertex2d(-0.3016381994088, 0.6497451195247);
    glVertex2d(0.1907792676124, 0.625577391082);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(-0.3137220636302, 1.2237286700402);
    glVertex2d(-0.5161267893383, 0.6829757461335);
    glVertex2d(-0.9662507315847, 0.6950596103549);
    glVertex2d(-1.1324038646286, 1.2599802627044);
    glEnd();

                        glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(-1.3238515141161, 1.2676193985525);
    glVertex2d(-1.5699844709634, 0.7305957552566);
    glVertex2d(-1.1392003634575, 0.7063262280732);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(-1.5548160164737, 1.2736264259858);
    glVertex2d(-1.7732417611246, 0.75486528244);
    glVertex2d(-2.2040258686304, 0.7639663551338);
    glVertex2d(-2.4084229136924, 1.316182297041);
    glEnd();

                            glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(-2.5217363434989, 1.3053905418213);
    glVertex2d(-2.8186244991048, 0.7900140767641);
    glVertex2d(-2.3557104135268, 0.7670000460317);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(-2.7051961822332, 1.3377658074803);
    glVertex2d(-2.952547873555, 0.8077436451142);
    glVertex2d(-3.3904726386819, 0.8197615569364);
    glVertex2d(-3.647732479293, 1.3883807874067);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(-3.8136288056623, 1.3666562684774);
    glVertex2d(-3.5707091849073, 0.8274932077772);
    glVertex2d(-4.0466736450859, 0.8452678141739);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(-4.231205223655, 0.8728724563146);
    glVertex2d(-4, 1.4);
    glVertex2d(-4.8898987464179, 1.4729151859547);
    glVertex2d(-4.6823651707529, 0.8683608568436);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(-5.0663635139218, 1.4743830397894);
    glVertex2d(-4.8318173445719, 0.8758016700943);
    glVertex2d(-5.1885229771248, 0.8929039949427);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(-5.6625016943528, 1.5061445002222);
    glVertex2d(-5.2520458979904, 1.4865989861097);
    glVertex2d(-5.354852869961, 0.9043079790323);
    glVertex2d(-5.6820472084653, 0.9246654553755);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(147,98,58);
    glVertex2d(-5.9603379519082, 0.8946680588087);
    glVertex2d(-5.9609232050407, 1.5255182380734);
    glVertex2d(-9.7902302255364, 1.7316616055897);
    glVertex2d(-9.8120020064907, 1.0379816607265);
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(54,28,13);
    glVertex2d(21.5766996952344, -13.3304681048546);
    glVertex2d(21.5283468546306, -11.917343492802);
    glVertex2d(20.4919774422981, -11.5622826437673);
    glVertex2d(20.3669573850521, -12.9050587034059);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(54,28,13);
    glVertex2d(21.5766996952344, -13.3304681048546);
    glVertex2d(21.5283468546306, -11.917343492802);
    glVertex2d(23.9016108661709, -11.9060690794455);
    glVertex2d(23.9918061730227, -13.3153707490062);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(54,28,13);
    glVertex2d(21.475282574025, -10.6848040733025);
    glVertex2d(21.5283468546306, -11.917343492802);
    glVertex2d(20.4919774422981, -11.5622826437673);
    glVertex2d(20.4435439345874, -10.3491404839333);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(54,28,13);
    glVertex2d(21.475282574025, -10.6848040733025);
    glVertex2d(21.5283468546306, -11.917343492802);
    glVertex2d(23.9016108661709, -11.9060690794455);
    glVertex2d(23.8456609031394, -10.6204138144494);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(168,112,73);
    glVertex2d(21.475282574025, -10.6848040733025);
    glVertex2d(20.4435439345874, -10.3491404839333);
    glVertex2d(22.9756355247147, -10.3067027404982);
    glVertex2d(23.8456609031394, -10.6204138144494);
    glEnd();


            glBegin(GL_POLYGON);
    glColor3ub(168,112,73);
    glVertex2d(22.808529670172, -12.6521470802001);
    glVertex2d(24.0327578045253, -12.973303460595);
    glVertex2d(21.3681364356239, -13.003739129578);
    glVertex2d(20.1813124640079, -12.6406924684127);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(54,28,13);
    glVertex2d(20.1813124640079, -12.6406924684127);
    glVertex2d(21.3681364356239, -13.003739129578);
    glVertex2d(21.4076942311918, -14.2403208603917);
    glVertex2d(20.2216001623013, -13.9071095051539);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(54,28,13);
    glVertex2d(21.3681364356239, -13.003739129578);
    glVertex2d(21.4076942311918, -14.2403208603917);
    glVertex2d(24.1179773596637, -14.0583380110691);
    glVertex2d(24.0327578045253, -12.973303460595);
    glEnd();

I_AnimatedTextAdder("They Started building this planet here                                                     ", -6.0, 15.0);
glutTimerFunc(4000,I_Timer,0);
I_AnimatedTextAdder("Together, they began building anew, blending Earth's knowledge with a commitment to protect their new home.", -6.0, 12.0);
glutTimerFunc(4000,I_Timer,0);
I_AnimatedTextAdder("What Do You Think, How Will They Do In The Future?                                                                              ", -6.0, 9.0);
glutTimerFunc(2000,I_Timer,0);



    glutSwapBuffers();
}

void IdrawEarth() {
    glBegin(GL_POLYGON);

    glColor3ub(7, 110, 96);
    glVertex2d(16.0089037269473 * 25 / 16, 3.35 * 20 / 9); // z

    glColor3ub(41, 44, 56);
    glVertex2d(15.5122233009138 * 25 / 16, 3.4237139438823 * 20 / 9); // W

    glColor3ub(168, 215, 185);
    glVertex2d(14.4285378938879 * 25 / 16, 3.5341532210315 * 20 / 9); // V

    glColor3ub(58, 72, 78);
    glVertex2d(13.0273395650583 * 25 / 16, 3.6652998626461 * 20 / 9); // U

    glColor3ub(68, 86, 91);
    glVertex2d(10.9850087657944 * 25 / 16, 3.765662970606 * 20 / 9); // T
    glVertex2d(9.9827045618432 * 25 / 16, 3.7559318618298 * 20 / 9); // S

    glColor3ub(89, 124, 125);
    glVertex2d(8.114331676808 * 25 / 16, 3.7464696442774 * 20 / 9); // R
    glVertex2d(5.9929499635908 * 25 / 16, 3.7464696442774 * 20 / 9); // Q
    glVertex2d(2.5 * 25 / 16, 3.6 * 20 / 9);                           // P

    glColor3ub(198, 223, 213);
    glVertex2d(-0.0171433212294 * 25 / 16, 3.2746748117356 * 20 / 9); // O
    glVertex2d(-3.0069964832908 * 25 / 16, 2.8002370345223 * 20 / 9); // N
    glVertex2d(-5.9550766738109 * 25 / 16, 2.1530044718343 * 20 / 9); // M
    glVertex2d(-8.8906669384693 * 25 / 16, 1.4094248797308 * 20 / 9); // K

    glColor3ub(236, 243, 235);
    glVertex2d(-10.1686943623971 * 25 / 16, 1.0376350836791 * 20 / 9); // J
    glVertex2d(-13.029207707811 * 25 / 16, 0.0912020031964 * 20 / 9);  // G

    glColor3ub(216, 227, 211);
    glVertex2d(-15 * 25 / 16, -0.6 * 20 / 9);                          // D

    glColor3ub(246, 249, 241);
    glVertex2d(-16.0089037269473 * 25 / 16, -1.0929610779818 * 20 / 9); // C

    glColor3ub(93, 91, 79);
    glVertex2d(-16 * 25 / 16, -9 * 20 / 9);                            // A

    glColor3ub(81, 76, 65);
    glVertex2d(-11 * 25 / 16, -9 * 20 / 9);                            // B

    glColor3ub(60, 50, 50);
    glVertex2d(-6 * 25 / 16, -9 * 20 / 9);                             // E

    glColor3ub(40, 40, 40);
    glVertex2d(0, -9 * 20 / 9);                                        // F

    glColor3ub(30, 30, 30);
    glVertex2d(6 * 25 / 16, -9 * 20 / 9);                              // H

    glColor3ub(12, 12, 12);
    glVertex2d(10 * 25 / 16, -9 * 20 / 9);                             // I

    glColor3ub(1, 1, 1);
    glVertex2d(14 * 25 / 16, -9 * 20 / 9);                             // L

    glColor3ub(0, 0, 0);
    glVertex2d(16 * 25 / 16, -9 * 20 / 9);                             // M

    glEnd();
}


void Rocket(){
    glLineWidth(5);
    glPushMatrix();
    glTranslatef(RocketPositionX,RocketPositionYS,0);
    glRotatef(RocketAngleS,0,0,1);
    glScalef(RocketSizeS,RocketSizeS,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.95f, 0.950f, 0.950f);
    glVertex2f(-0.5f, 6.0f);
    glVertex2f(0.5f, 6.0f);
    glVertex2f(0.0f, 7.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.70f, 0.70f, 0.70f);
    glVertex2f(-0.5f, 6.0f);
    glVertex2f(-2.0f, 4.0f);
    glVertex2f(-2.5f, 3.0f);
    glVertex2f(-2.5f, -4.0f);
    glVertex2f(2.5f, -4.0f);
    glVertex2f(2.5f, 3.0f);
    glVertex2f(2.0f, 4.0f);
    glVertex2f(0.5f, 6.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.40f, 0.40f, 0.40f);
    glVertex2f(-0.50f, 5.90f);
    glVertex2f(-1.5f, 4.0f);
    glVertex2f(-2.0f, -5.0f);
    glVertex2f(2.0f, -5.0f);
    glVertex2f(1.5f, 4.0f);
    glVertex2f(0.50f, 5.90f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.40f, 0.40f, 0.40f);
    glVertex2f(-1.0f, 2.0f);
    glVertex2f(-3.0f, -0.50f);
    glVertex2f(-3.0f, -1.50f);
    glVertex2f(-5.5f, -3.0f);
    glVertex2f(-5.5f, -5.0f);
    glVertex2f(-1.0f, -3.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.40f, 0.40f, 0.40f);
    glVertex2f(1.0f, 2.0f);
    glVertex2f(3.0f, -0.50f);
    glVertex2f(3.0f, -1.50f);
    glVertex2f(5.5f, -3.0f);
    glVertex2f(5.5f, -5.0f);
    glVertex2f(1.0f, -3.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.767, 0.975, 0.979);
    glVertex2f(-0.50f, 5.0f);
    glVertex2f(-1.2f, 4.0f);
    glVertex2f(-1.42f, 1.3f);
    glVertex2f(1.42f, 1.3f);
    glVertex2f(1.2f, 4.0f);
    glVertex2f(0.50f, 5.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.80f, 0.20f, 0.20f);
    glVertex2f(-1.58f, 1.3f);
    glVertex2f(-1.98f, 0.8f);
    glVertex2f(1.98f, 0.8f);
    glVertex2f(1.58f, 1.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.80f, 0.20f, 0.20f);
    glVertex2f(-5.5f, -5.0f);
    glVertex2f(-5.5f, -3.0f);
    glVertex2f(-6.2f, -3.0f);
    glVertex2f(-6.2f, -5.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.80f, 0.20f, 0.20f);
    glVertex2f(5.5f, -5.0f);
    glVertex2f(5.5f, -3.0f);
    glVertex2f(6.2f, -3.0f);
    glVertex2f(6.2f, -5.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(4.0, -5.0f);
    glVertex2f(4.0f, -1.0f);
    glVertex2f(5.4f, -1.0f);
    glVertex2f(5.4f, -5.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.937, 0.937, 0.949);
    glVertex2f(4.0f, -1.0f);
    glVertex2f(5.4f, -1.0f);
    glVertex2f(4.75f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-4.0, -5.0f);
    glVertex2f(-4.0f, -1.0f);
    glVertex2f(-5.4f, -1.0f);
    glVertex2f(-5.4f, -5.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.937, 0.937, 0.949);
    glVertex2f(-4.0f, -1.0f);
    glVertex2f(-5.4f, -1.0f);
    glVertex2f(-4.75f, 0.0f);
    glEnd();
    //missile2
    glBegin(GL_POLYGON);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(2.0, 0.7f);
    glVertex2f(2.0f, -3.5f);
    glVertex2f(3.4f, -4.0f);
    glVertex2f(3.4f, -.75f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex2f(2.0f, 0.0f);
    glVertex2f(3.4f, -0.75f);
    glVertex2f(2.f, 1.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(-2.0, 0.7f);
    glVertex2f(-2.0f, -3.5f);
    glVertex2f(-3.4f, -4.0f);
    glVertex2f(-3.4f, -.75f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(-3.4f, -0.75f);
    glVertex2f(-2.f, 1.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, -3.5f);
    glVertex2f(1.0f, -3.5f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, -3.5f);
    glVertex2f(-1.2f, -3.5f);
    glVertex2f(-1.2f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, -3.5f);
    glVertex2f(1.2f, -3.5f);
    glVertex2f(1.2f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.90f, 0.90f, 0.90f);
    glVertex2f(-0.50f, -1.0f);
    glVertex2f(-0.50f, -2.5f);
    glVertex2f(0.50f, -2.5f);
    glVertex2f(0.50f, -1.0f);
    glEnd();
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3f(0.50f, 0.50f, 0.50f);
    glVertex2f(-0.25f, -1.10f);
    glVertex2f(-0.85f, -1.45f);
    glVertex2f(-0.25f, -1.60f);
    glVertex2f(-0.85f, -1.95f);
    glVertex2f(-0.25f, -2.10f);
    glVertex2f(-0.85f, -2.45f);
    glVertex2f(0.25f, -1.10f);
    glVertex2f(0.85f, -1.45f);
    glVertex2f(0.25f, -1.60f);
    glVertex2f(0.85f, -1.95f);
    glVertex2f(0.25f, -2.10f);
    glVertex2f(0.85f, -2.45f);
    glEnd();
    glColor3f(0.80f, 0.8f, 0.80f);
    glPushMatrix();
    glTranslatef(0.0f, 0.50f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(2.0f, -0.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);

    glTranslatef(-1.0f, -5.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(-1.0f, -0.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(2.0f, -0.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glPopMatrix();

    glBegin(GL_LINES);
    glColor4ub(0,0,0,0);
    glVertex2f(-3,5);
    glVertex2f(-3,5);
    glVertex2f(1.5,0);
    glVertex2f(-1.5,0);
    glVertex2f(1.5,-1);
    glVertex2f(-1.5,-1);
    glEnd();

    glPopMatrix();

}


void IRocketEneringScene(){
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    IbackgroundEntering();
    drawStaticStars(500);
    IdrawEarth();
   //rks();
   std::cout<<"yyyy"<<std::endl;

    if (1) {
        RocketPositionX += 0.3*25/16; // Move the rocket to the right
       //RocketPositionX += 0.2; // Move the rocket to the right
        RocketPositionYS += 0.1*20/9;
        RocketSizeS-=.006;

        if (RocketPositionX >= 1.4) {
            I_keyPressed = false;
             RocketPositionX = -5.4f;
             RocketPositionYS = -1.5f;
             RocketSizeS=.5;
             RocketAngleS=0;
            topViewScene=true;
            enteringScene=false;
            printf("hello");

        }
    }
    Rocket();
    I_AnimatedTextAdder("The Hopebringer trying to reaching out the new found planet",-8.5,-5.4);
    glutSwapBuffers();
}
void IkeyPpressed(){
glBegin(GL_POLYGON);
    glColor3ub(39,193,134);

  glVertex2d(18.8077671232137, -2.0105416756321);
  glVertex2d(17.8726998489911, -1.2689365960763);
  glVertex2d(17.2278258667687, -0.4306004191871);
  glVertex2d(16.2927585925462, 0.2465172621465);
  glVertex2d(15.2932039201014, 1.0526097399245);
  glVertex2d(13.9389685574343, 2.3101140052583);
  glVertex2d(13.1328760796563, 2.7937694919251);
  glVertex2d(12.3912710001005, 3.8900552617033);
  glVertex2d(10.9725482392112, 5.0830721288148);
  glVertex2d(8.1995901156547, 6.8242318808154);
  glVertex2d(6,8);
  glVertex2d(4.1046403285423, 8.565391632816);
  glVertex2d(1.4284133023192, 8.8878286239272);
  glColor3ub(17,167,110);

  glVertex2d(-1.9249314052374, 8.7910975265939);
  glVertex2d(-4.1819903430159, 8.2751983408159);
  glVertex2d(-5.536225705683, 7.9527613497047);
  glVertex2d(-7.5030913514614, 7.501349562149);
  glVertex2d(-9.1152763070175, 6.8564755799265);
  glVertex2d(-10.8886797581292, 6.1148705003707);
  glVertex2d(-14.269548307905, 4.4212988515584);
  glVertex2d(-16.321095457631, 3.1747891909653);
  glVertex2d(-17.126132946764, 2.5515343606688);
   glVertex2d(-18.3986115586194, 1.4868073589122);
  glVertex2d(-20, 0);
  glVertex2d(-21.2292272462161, -1.6814046950952);
  glVertex2d(-22.319923199235, -3.2655107220989);
  glVertex2d(-23.1768985908927, -4.7457409440531);
  glVertex2d(-24.9168183254705, -6.8232570450416);
  glVertex2d(-24.8991292649925, -16.6945182958206);
  glVertex2d(18.3178871192826, -16.1827274144468);
glEnd();

     //this is mini mountain
      glColor3ub(2,181,142);
    glBegin(GL_POLYGON);

  glColor3ub(2,181,142);
  glVertex2d(-14.3983383021601, -16.280130390041);
  glVertex2d(-13.8257533175189, -16.4664888721446);
  glVertex2d(-14.1359077551311, -15.5934615662734);
  glVertex2d(-14.5034981997084, -14.8812550799047);
  glVertex2d(-14.7562166303553, -14.2264846005013);
  glVertex2d(-14.9974478596092, -13.8014581489587);
  glColor3ub(3,139,134);
  glVertex2d(-15.2616534916492, -13.2960212876649);
  glVertex2d(-15.5832951306544, -12.4000195790076);
  glVertex2d(-15.9164239710526, -11.3891458564198);
  glVertex2d(-16.295501617023, -10.2978617240808);
  glVertex2d(-16.6745792629934, -9.1261671819904);
  glVertex2d(-17.1340673187151, -8.3335502858705);
  glVertex2d(-17.5131449646855, -7.7017542092532);
  glVertex2d(-18.2713002566263, -7.0469837298497);
  glVertex2d(-19.1213531597115, -6.564521271342);
  glVertex2d(-19.6497644237914, -6.3347772434811);
  glVertex2d(-20.7180741533444, -6.4381620560185);
  glVertex2d(-21.717460674539, -7.0469837298497);
  glVertex2d(-22.2688463414051, -7.667292605074);
  glVertex2d(-22.6134623831964, -8.1612422649749);
  glVertex2d(-23, -9);
  glVertex2d(-23.1878224528485, -9.815399265573);
  glVertex2d(-24.9983383021601, -16.280130390041);
glEnd();

    glBegin(GL_POLYGON);
   glColor3ub(2,181,142);

  glColor3ub(177,212,133);
  glVertex2d(-14.3983383021601, -16.280130390041);
  glVertex2d(-13.8257533175189, -16.4664888721446);
  glVertex2d(-14.1359077551311, -15.5934615662734);
  glVertex2d(-14.5034981997084, -14.8812550799047);
  glVertex2d(-14.7562166303553, -14.2264846005013);
  glVertex2d(-14.9974478596092, -13.8014581489587);
   glColor3ub(23,159,164);
  glVertex2d(-15.2616534916492, -13.2960212876649);
  glVertex2d(-15.5832951306544, -12.4000195790076);
  glVertex2d(-15.9164239710526, -11.3891458564198);
  glVertex2d(-16.295501617023, -10.2978617240808);
  glVertex2d(-16.6745792629934, -9.1261671819904);
  glVertex2d(-17.1340673187151, -8.3335502858705);
  glVertex2d(-17.5131449646855, -7.7017542092532);
  glVertex2d(-18.2713002566263, -7.0469837298497);
  glVertex2d(-19.1213531597115, -6.564521271342);
    int x = 1;
    int y = -.1;
    glVertex2d(-20.7180741533444 + x, -6.4381620560185 + y);
    glVertex2d(-21.717460674539 + x, -7.0469837298497 + y);
    glVertex2d(-22.2688463414051 + x, -7.667292605074 + y);
    glVertex2d(-22.6134623831964 + x, -8.1612422649749 + y);
    glVertex2d(-23 + x, -9 + y);
    glVertex2d(-23.1878224528485 + x, -9.815399265573 + y);
    glVertex2d(-24.9983383021601 + x, -16.280130390041 + y);

glEnd();



//this is front mountain
    glBegin(GL_POLYGON);
    glColor3ub(18,176,108);
    glVertex2d(-25,-17.3);
    glVertex2d(-25, -20);
    glVertex2d(25, -20);
    glColor3ub(122,197,80);
    glVertex2d(25, -0.5);
    glVertex2d(24.0173943416908, -0.697981690927);
    glVertex2d(22.6907580871153, -1.0337353100779);
    glVertex2d(21.323176269127, -1.3858671554281);
    glVertex2d(20.0538638033294, -1.746188113461);
    glVertex2d(18.669903759976, -2.1556437475892);
    glVertex2d(17.3678348434482, -2.5814776070826);
    glVertex2d(16.3441957581276, -2.9336094524329);
    glVertex2d(13.6945601681687, -3.8720489142018);
    glVertex2d(11.8011114880978, -4.6222832968714);
    glVertex2d(9.9255255314238, -5.3189295093503);
    glVertex2d(8.4965076596722, -5.890536658051);
    glVertex2d(7.1884367866221, -6.4073848164218);
    glVertex2d(5.5688088403747, -7.0629485089505);
    glVertex2d(4.5404736364081, -7.4742825905372);
    glVertex2d(3.1907836812019, -8.065575332818);
    glVertex2d(2.2267194274832, -8.4897636044542);
    glVertex2d(1.2498009837149, -8.92680606614);
    glVertex2d(0.1957573996491, -9.4923904283217);
    glVertex2d(-0.7040359038217, -9.9551412701067);
    glVertex2d(-1.835204628185, -10.4950172521891);
    glVertex2d(-3.5319577147299, -11.3433937954616);
  glVertex2d(-5.1644398510269, -12.1660619586349);
  glVertex2d(-6.1927750549935, -12.6802295606182);
  glVertex2d(-6.7851887788835, -12.9314414887425);
  glVertex2d(-7.4321190936745, -13.1509357026894);
  glVertex2d(-7.9288691568175, -13.3415490990118);
  glVertex2d(-8.685546578582, -13.5610433129587);
  glVertex2d(-9.3209245663231, -13.7458805457561);
  glVertex2d(-10.0833781516124, -13.9538224326532);
  glVertex2d(-10.5685758877056, -14.109778847826);
  glVertex2d(-11.4223984768178, -14.3211911182974);
  glVertex2d(-12.3814319582158, -14.4904361541364);
  glVertex2d(-13.3965544120847, -14.6695754107015);
  glVertex2d(-14.3420115995117, -14.8039298531254);
  glVertex2d(-15.1531143445148, -14.9233560241688);
  glVertex2d(-16.1682367983837, -15.0278539238317);
  glVertex2d(-17.372450689738, -15.1572322757954);
  glVertex2d(-18.288051334404, -15.211969270857);
  glVertex2d(-18.7657560185776, -15.246801904078);
  glVertex2d(-20.1558539283813, -15.3030228248847);
  glVertex2d(-21.0418815426101, -15.3077357377263);
  glVertex2d(-21.7912346844312, -15.3077357377263);
  glVertex2d(-23.0024532847332, -15.3360132147762);
  glVertex2d(-23.9198181445945, -15.2946982718182);
  glVertex2d(-24.6727851224486, -15.2643774539181);
  glVertex2d(-25.0164210586504, -15.244163575318);
    glEnd();


    //WApplyTexture(-25, -20, 25, -20, 25, -6, -25, -6,textures[1].textureID);



}
void IRocketLandingScene(){
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3ub(4,22,93);
    glBegin(GL_POLYGON);
        glVertex2d(-25,-20);
        glVertex2d(-0,-20);
        glVertex2d(25,-20);
        glColor3ub(180,111,174);
        glVertex2d(25,20);
        glVertex2d(0,20);
        glColor3ub(4,22,93);
        glVertex2d(-25,20);
    glEnd();
    drawStaticStars(500);
    IkeyPpressed();


    Rocket();
    RocketSizeS=.3;
    if(RocketPositionYS>-13.5)
        {
            RocketPositionYS-=.12;

    }
    else if(RocketPositionYS<-13.51)
    {
    if(text1){I_AnimatedTextAdder("Landed Successfully                                                         ", -6.0, 0.0);}

    if(text2){I_AnimatedTextAdder("The Hopebringer touched down on the fertile grounds of the newfound planet.",-10.5,-12);}

    if(text3){I_AnimatedTextAdder("The pioneers, filled with awe, stepped onto the untouched soil. The first settlement, named \"New Beginnings\"",-10.5,-12);}

    if(text4){I_AnimatedTextAdder("                                                                                                               ",-10.5,-12);}
    }
glutSwapBuffers();
}
bool moveRight = true;
    int  flag=0;

void IRocketTopViewScene() {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // I_MorphEffect();
   printf("kjkkkjkk");
    IdrawRunningBg();
    Rocket();
    RocketPositionX += (moveRight ? 1 : -1) * 0.08 * 25 / 16;
    if (RocketPositionX > 3.4f) {
        moveRight = false;
        flag+=1;
    }

    if (RocketPositionX < -5.4f) {
        moveRight = true;
        flag+=1;
    }
    if(flag>=4){
        topViewScene=false;
        landingScene2=true;
        RocketPositionX=-16;
        RocketPositionYS=25;

    }
    glutSwapBuffers();
}

void Ikeyboard(unsigned char key, int x, int y){
    if (key == 'p' || key == 'P') {
        I_keyPressed = true;
        std::cout<<"WORKING"<<std::endl;
    }
    if (key == 'l' || key == 'L')  {
        landingScene2=false;
        currentLength=0;
        topViewScene=false;
        campingScene=false;
        campingScene = true;
                std::cout<<"WORKINGL"<<std::endl;

    }
    if (key == 't' || key == 'T'){
        enteringScene=false;
        topViewScene=false;
        campingScene=false;
        campingScene=false;
        AkashScene=true;
        text1=true;
        text2=false;
        text3=false;
        text4=false;

    }
    if(key=='a' || key=='A')  {
        if(text2){
            text2=false;
            text1=true;
        }
        else if(text3){
            text3=false;
            text2=true;
        }
        else if(text4){
            text3=true;
            text4=false;
        }
    }
    if((key=='d' || key=='D')) {

        if(text1){
            text1=false;
            text2=true;
        }
        else if(text2){
            text2=false;
            text3=true;
        }
        else if(text3){
            text3=false;
            text4=true;
        }
    }
    switch (key) {
        case 'm':
            dayBackground = !dayBackground;
            break;
        case 'z':
            liftUp = true;
            break;
        case 'x':
            liftUp = false;
            FlyingObject1PositionY = -9.0;
            FlyingObject1PositionX = -15.0;
            break;
        case 'c':
            liftUpObject2 = true;
            break;
        case 'v':
            liftUpObject2 = false;
            FlyingObject2PositionY = 0.0;
            FlyingObject2PositionX = -15.0;
            break;
    }
        glutPostRedisplay();


}
void update(int value) {
    box1X += box1Speed;

std::cout<<box1X<<std::endl;

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update, 0);
}


void IDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);

    if(enteringScene){
        IRocketEneringScene();
    }
    if(topViewScene){
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

       IRocketTopViewScene();
        box1X += 1;
        glutPostRedisplay();
    }
    if(landingScene2){
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        IRocketLandingScene();
        }
    if(campingScene){
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        IDrawCampingScene();

    }

    glutSwapBuffers();
}


//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//---------------esme--Abha-----------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------

void car();
//AB001
void E_Circle(float radius,int steps,float X,float Y,int CC1,int CC2=0,int CC3=0,int CC4=0){

    float Radius = radius;
    int Steps = steps;
    float Pi=3.1416f;
    glPushMatrix();
    glTranslatef(X, Y, 0);
    glBegin(GL_POLYGON);
    if(CC2 == 0 && CC3 == 0 && CC4 == 0) glColor3ub(CC1,CC1,CC1);
    else glColor4ub(CC1,CC2,CC3,CC4);
    for(int i=0;i<Steps;i++)
        {
            float A=(i*2*Pi)/Steps;
            float x = Radius * cos(A);
            float y = Radius * sin(A);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
}

//AB002
void E_CirclePoints(float radius,int steps,float X,float Y,int PointSize,int r,int g,int b){

    float Radius = radius;              //Circle's Radius
    int Steps = steps;                  //Increase to get Smooth Circle
    float Pi=3.1416f;                   //PI
    glPushMatrix();
    glTranslatef(X, Y, 0);              //Move Circle Along Axes
    glPointSize(PointSize);             //Point Size
    glBegin(GL_POINTS);
    glColor3ub(r,g,b);  // Color

    for(int i=0;i<Steps;i++)
        {
            float A=(i*2*Pi)/Steps;
            float x = Radius * cos(A);
            float y = Radius * sin(A);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
}
void E_scale(int value)
            {
        _scale += 0.2; // Increase scale after each iteration
            if (_scale > 1.0)
            {
            _scale = 0.0;
            }
            glutPostRedisplay();
            glutTimerFunc(200, E_scale, 0);// Reset scale to 0 after reaching 2.0
            }
void E_DrawTextStroke(float x,float y,float z,float FSize,float Density,char *CharectersArray, void* font=GLUT_STROKE_MONO_ROMAN){
	char Charecter;
    glLineWidth(Density);
    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(FSize/1.7,FSize,FSize);

	for(int i = 0; *(CharectersArray+i)!='\0' ;i++)
	{
	    Charecter = *(CharectersArray + i);
        glutStrokeCharacter(font ,Charecter);
        //glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, Charecter);

	}
    glPopMatrix();
}
LPSTR E_StringToSLPSTR(string s){
return const_cast<char *>(s.c_str());
}
//AB003
void E_Sky(){
    glBegin(GL_QUADS);
    glColor3ub(236,246, 255);
    glVertex2f(-50,-30);
    glColor3ub(190,215, 255);
    glVertex2f(-50,60);
    glColor3ub(190,215, 255);
    glVertex2f(50,60);
    glColor3ub(236,246, 255);
    glVertex2f(50,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(190,215, 255);
    glVertex2f(-50,40);
    glColor3ub(0,0,20);
    glVertex2f(-50,120);
    glColor3ub(0,0,20);
    glVertex2f(50,120);
    glColor3ub(190,215, 255);
    glVertex2f(50,40);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(10,10,10);
    glVertex2f(-50,120);
    glVertex2f(-50,210);
    glVertex2f(50,210);
    glVertex2f(50,120);
    glEnd();
}
//AB004
void E_Windows1(float x, float y, float width, float height, float alpha) {
    glColor4f(0.7, 0.9, 1.0, alpha); // Light blue color for windows

    int numWindows = 5; // Adjust the number of windows as needed
    float windowWidth = width / 4;
    float windowHeight = height / 4.5;
    float spacingX = (width - numWindows * windowWidth) / (numWindows + 1);
    float spacingY = height / 9.5;

    for (int i = 0; i < numWindows; ++i) {
        float windowX = x + (i + 1) * spacingX + i * windowWidth;
        for (int j = 0; j < 4; ++j) {
            float windowY = y + (j + 1) * spacingY + j * windowHeight;
            glBegin(GL_POLYGON);
            glVertex2f(windowX, windowY);
            glVertex2f(windowX + windowWidth, windowY);
            glVertex2f(windowX + windowWidth, windowY + windowHeight);
            glVertex2f(windowX, windowY + windowHeight);
            glEnd();
        }
    }
}
//AB005
void E_Windows2(float x, float y, float width, float height, float alpha) {
    glColor4f(0.7, 0.9, 1.0, alpha);

    int numWindows = 4;
    float windowWidth = width * 0.2;
    float windowHeight = height * 0.2;
    float spacing = (width - numWindows * windowWidth) / (numWindows + 1);

    for (int i = 0; i < numWindows; ++i) {
        float windowX = x + (i + 1) * spacing + i * windowWidth;
        float windowY = y + height * 0.6;
        glBegin(GL_POLYGON);
        glVertex2f(windowX, windowY);
        glVertex2f(windowX + windowWidth, windowY);
        glVertex2f(windowX + windowWidth, windowY + windowHeight);
        glVertex2f(windowX, windowY + windowHeight);
        glEnd();
    }
}
//AB006
void E_buildingtype1(float x, float y, float height, float width, float r, float g, float b, float alpha) {
    // Set color with opacity
    glColor4f(r, g, b, alpha-0.5);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
    glColor4f(0.4, 0.2, 0.0, alpha); // Brown color for the door
    float doorWidth = width * 0.2;
    float doorHeight = height * 0.35;
    float doorX = x + (width - doorWidth) / 2;
    float doorY = y;
    glBegin(GL_POLYGON);
    glVertex2f(doorX, doorY);
    glVertex2f(doorX + doorWidth, doorY);
    glVertex2f(doorX + doorWidth, doorY + doorHeight);
    glVertex2f(doorX, doorY + doorHeight);
    glEnd();
    E_Windows2(x, y, width, height, alpha);
}
//AB007
void E_buildingtype2(float x, float y, float height, float width, float r, float g, float b, float alpha) {
    // Set color with opacity
    glColor4f(r, g, b, alpha);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x + width / 2, y + height + width / 2);
    glVertex2f(x, y + height);
    glEnd();
    glColor4f(0.4, 0.2, 0.0, alpha);
    float doorWidth = width * 0.4;
    float doorHeight = height * 0.2;
    float doorX = x + (width - doorWidth) / 2;
    float doorY = y;
    glBegin(GL_POLYGON);
    glVertex2f(doorX, doorY);
    glVertex2f(doorX + doorWidth, doorY);
    glVertex2f(doorX + doorWidth, doorY + doorHeight);
    glVertex2f(doorX, doorY + doorHeight);
    glEnd();
    E_Windows1(x + width * 0.2, y + height * 0.1, width * 0.6, height * 0.7, alpha);
}
//AB008
void E_workshopBuilding(float x, float y, float height, float width, float r, float g, float b, float alpha) {
    // Set color with opacity
    glColor4f(r, g, b, alpha);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x , y + height +4  );
    glVertex2f(x, y + height);
    glEnd();

    glColor4f(0.4, 0.2, 0.30, alpha); // Brown color for the door
    float doorWidth = width * 0.35;
    float doorHeight = height * 0.28;
    float doorX = x + (width - doorWidth) / 2;
    float doorY = y;
    glBegin(GL_POLYGON);
    glVertex2f(doorX, doorY);
    glVertex2f(doorX + doorWidth, doorY);
    glVertex2f(doorX + doorWidth, doorY + doorHeight);
    glVertex2f(doorX, doorY + doorHeight);
    glEnd();
    glColor4f(0.753, 0.941, 1, alpha);
    int num = 4; // Adjust the number of windows as needed
    float Width = width / 5;
    float Height = height / 4;
    float spacingX = (width - num * Width) / (num + 1);
    float spacingY = height / 6;

    for (int i = 0; i < num; ++i) {
        float X = x + (i + 1) * spacingX + i * Width;
        float Y = y + height * 0.4;
        glBegin(GL_POLYGON);
        glVertex2f(X, Y);
        glVertex2f(X + Width, Y);
        glVertex2f(X + Width, Y + Height);
        glVertex2f(X, Y + Height);
        glEnd();
    }
    glBegin(GL_POLYGON);
    glVertex2f(8.8f,-5.0f);
    glVertex2f(28.0f,-5.0f);
    glVertex2f(28.0f,-5.0f+3.0f);
    glVertex2f(8.8f,-5.0f+3.0f);
    glEnd();
     glColor3f(0.0f, 0.0f, 1.0f);
    glPushMatrix();
    glTranslatef(9.6f, 0.1f, 0.0f);
    glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0,0.70,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
	glFlush();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9.6f, 0.1f, 0.0f);
    glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.9,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
	glFlush();
    glPopMatrix();
    //satdish
glBegin(GL_POLYGON);
glColor3ub(100, 100, 100);
glVertex2f(17,0.04);
glVertex2f(16,0.24);
glVertex2f(16,2.5);
glVertex2f(17,2.5);
glEnd();

//Antena
glPointSize(3);
glColor3ub(205,205,205);
glColor3ub(0,0,0);
}
//AB009
void E_fire(float x,float y){
    if(IsFire){
 glPushMatrix();
glTranslatef(x,y,0);

        glScalef(1.8,-_scale+1.5,0);
        glRotatef(180,0,0,1);
        glBegin(GL_POLYGON);
        glColor3ub(250,168,4);
        glVertex2f(-6.63022604633, -4.2481012424478);
        glVertex2f(-6.7465559980783, -4.2297333553297);
        glVertex2f(-6.8934990950236, -4.1929975810933);
        glVertex2f(-7.0281969338902, -4.1072807745419);
        glVertex2f(-7.1077911114022, -4.0093187099117);
        glVertex2f(-7.1751400308355, -3.9236019033603);
        glVertex2f(-7.2363663212293, -3.7950266935332);
        glVertex2f(-7.2975926116232, -3.6603288546666);
        glVertex2f(-7.2975926116232, -3.5378762738789);
        glVertex2f(-7.3037152406626, -3.4031784350124);
        glVertex2f(-7.2731342956184, -3.2530613230128);
        glVertex2f(-7.2317340992589, -3.1150606684812);
        glVertex2f(-7.1855082943277, -3.0266532824312);
        glVertex2f(-7.1666570335488, -3.0989164487502);
        glVertex2f(-7.14780577277, -3.1586121078832);
        glVertex2f(-7.1038194976193, -3.2403009045916);
        glVertex2f(-7.0786844832475, -3.2811453029458);
        glVertex2f(-7.0472657152827, -3.1806052454586);
        glVertex2f(-7.0127050705215, -3.0926326951572);
        glVertex2f(-6.9718606721673, -2.9889507608735);
        glVertex2f(-6.9121650130342, -2.8632756890144);
        glVertex2f(-6.8493274771047, -2.7784450155095);
        glVertex2f(-6.7770643107857, -2.6779049580223);
        glVertex2f(-6.6985173908738, -2.5899324077209);
        glVertex2f(-6.6168285941654, -2.5019598574196);
        glVertex2f(-6.5382816742535, -2.4391223214901);
        glVertex2f(-6.462876631138, -2.3919941695429);
        glVertex2f(-6.4785860151204, -2.5082436110125);
        glVertex2f(-6.4848697687134, -2.5962161613139);
        glVertex2f(-6.4785860151204, -2.6873305884117);
        glVertex2f(-6.4660185079345, -2.7753031387131);
        glVertex2f(-6.4471672471556, -2.853850058625);
        glVertex2f(-6.4094647255979, -2.9166875945545);
        glVertex2f(-6.3780459576332, -2.9669576232982);
        glVertex2f(-6.3277759288895, -3.0423626664136);
        glVertex2f(-6.2743640233494, -3.117767709529);
        glVertex2f(-6.2303777481988, -3.2025983830339);
        glVertex2f(-6.2021008570305, -3.2811453029458);
        glVertex2f(-6.1738239658622, -3.3345572084859);
        glVertex2f(-6.1549727050833, -3.3785434836366);
        glVertex2f(-6.0984189227467, -3.2780034261494);
        glVertex2f(-6.0324395100207, -3.1806052454586);
        glVertex2f(-5.9538925901088, -3.124051463122);
        glVertex2f(-5.9732645569233, -3.1875985965982);
        glVertex2f(-5.9850346874527, -3.2582193797749);
        glVertex2f(-6, -3.3);
        glVertex2f(-6.0068935012931, -3.3372473990441);
        glVertex2f(-6.0035306068562, -3.4196383127502);
        glVertex2f(-6.0035306068562, -3.4196383127502);
        glVertex2f(-6.0018491596377, -3.48689620149);
        glVertex2f(-6.0055175561859, -3.6216138681457);
        glVertex2f(-6.0132346222923, -3.7367462720148);
        glVertex2f(-6.0307633596626, -3.8384129487625);
        glVertex2f(-6.0728323293513, -3.92255088814);
        glVertex2f(-6.1219127939881, -4.0031830800433);
        glVertex2f(-6.1955334909434, -4.0627807871023);
        glVertex2f(-6.2621426929505, -4.1293899891094);
        glVertex2f(-6.3287518949576, -4.1819762012203);
        glVertex2f(-6.4, -4.2);
            glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(250,78,4);
        glVertex2f(-6.6337519252008, -4.2555968981756);
        glVertex2f(-6.5531197332974, -4.2415739082793);
        glVertex2f(-6.4759932888681, -4.2275509183831);
        glVertex2f(-6.4, -4.2);
        glVertex2f(-6.3287518949576, -4.1539302214279);
        glVertex2f(-6.2726599353727, -4.1083555042651);
        glVertex2f(-6.2380960326952, -4.0683761592356);
        glVertex2f(-6.2, -4);
        glVertex2f(-6.1826867471704, -3.9199584301513);
        glVertex2f(-6.1727922318981, -3.8546546293541);
        glVertex2f(-6.1628977166258, -3.7873719255026);
        glVertex2f(-6.1668555227347, -3.7557094766312);
        glVertex2f(-6.202475777715, -3.7656039919035);
        glVertex2f(-6.249969451022, -3.7398782521956);
        glVertex2f(-6.2816318998933, -3.7062369002698);
        glVertex2f(-6.3172521548736, -3.6587432269628);
        glVertex2f(-6.3172521548736, -3.6053128444924);
        glVertex2f(-6.319231057928, -3.5597980742399);
        glVertex2f(-6.344956797636, -3.5182411100962);
        glVertex2f(-6.3726614403984, -3.4766841459526);
        glVertex2f(-6.3944293739974, -3.4371060848635);
        glVertex2f(-6.4221340167598, -3.3915913146109);
        glVertex2f(-6.4597331747945, -3.3520132535217);
        glVertex2f(-6.5, -3.3);
        glVertex2f(-6.5230580725372, -3.2629626160711);
        glVertex2f(-6.5487838122452, -3.2095322336008);
        glVertex2f(-6.5764884550076, -3.1640174633482);
        glVertex2f(-6.5923196794433, -3.1185026930957);
        glVertex2f(-6.6148690407736, -3.0553333670344);
        glVertex2f(-6.639136829248, -2.9916304222892);
        glVertex2f(-6.6816054590781, -3.0462329463565);
        glVertex2f(-6.7119401946711, -3.0887015761867);
        glVertex2f(-6.7544088245012, -3.1402706266947);
        glVertex2f(-6.8, -3.2);
        glVertex2f(-6.8277637305715, -3.272916152333);
        glVertex2f(-6.8360368402787, -3.3446164364619);
        glVertex2f(-6.8608561694002, -3.4080436108835);
        glVertex2f(-6.8884332017574, -3.482501598248);
        glVertex2f(-6.9049794211717, -3.5321402564911);
        glVertex2f(-6.9491026729433, -3.5790212114984);
        glVertex2f(-7, -3.6);
        glVertex2f(-7.0704416153152, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6865716376916);
        glVertex2f(-7.1311110865011, -3.7444834056418);
        glVertex2f(-7.1200802735582, -3.8079105800635);
        glVertex2f(-7.1145648670868, -3.8575492383065);
        glVertex2f(-7.1035340541439, -3.912703303021);
        glVertex2f(-7.0897455379652, -3.9816458839141);
        glVertex2f(-7.0594108023723, -4.0505884648071);
        glVertex2f(-6.9904682214792, -4.1305618586431);
        glVertex2f(-6.9353141567647, -4.1664120007075);
        glVertex2f(-6.8774023888145, -4.1939890330648);
        glVertex2f(-6.8112175111571, -4.2270814718935);
        glVertex2f(-6.7615788529141, -4.2491430977793);
        glVertex2f(-6.7091824914354, -4.2601739107222);
        glVertex2f(-6.7544088245012, -3.1402706266947);
        glVertex2f(-6.8, -3.2);
        glVertex2f(-6.8277637305715, -3.272916152333);
        glVertex2f(-6.8360368402787, -3.3446164364619);
        glVertex2f(-6.8608561694002, -3.4080436108835);
        glVertex2f(-6.8884332017574, -3.482501598248);
        glVertex2f(-6.9049794211717, -3.5321402564911);
        glVertex2f(-6.9491026729433, -3.5790212114984);
        glVertex2f(-7, -3.6);
        glVertex2f(-7.0704416153152, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6865716376916);
        glVertex2f(-7.1311110865011, -3.7444834056418);
        glVertex2f(-7.1200802735582, -3.8079105800635);
        glVertex2f(-7.1145648670868, -3.8575492383065);
        glVertex2f(-7.1035340541439, -3.912703303021);
        glVertex2f(-7.0897455379652, -3.9816458839141);
        glVertex2f(-7.0594108023723, -4.0505884648071);
        glVertex2f(-6.9904682214792, -4.1305618586431);
        glVertex2f(-6.9353141567647, -4.1664120007075);
        glVertex2f(-6.8774023888145, -4.1939890330648);
        glVertex2f(-6.8112175111571, -4.2270814718935);
        glVertex2f(-6.7615788529141, -4.2491430977793);
        glVertex2f(-6.7091824914354, -4.2601739107222);
        glVertex2f(-6.6816054590781, -4.2601739107222);
        glVertex2f(-6.6337519252008, -4.2555968981756);
        glVertex2f(-6.5531197332974, -4.2415739082793);
        glVertex2f(-6.4759932888681, -4.2275509183831);
        glVertex2f(-6.4, -4.2);
        glVertex2f(-6.3287518949576, -4.1539302214279);
        glVertex2f(-6.2726599353727, -4.1083555042651);
        glVertex2f(-6.2380960326952, -4.0683761592356);
        glVertex2f(-6.2, -4);
        glVertex2f(-6.1826867471704, -3.9199584301513);
        glVertex2f(-6.1727922318981, -3.8546546293541);
        glVertex2f(-6.1628977166258, -3.7873719255026);
        glVertex2f(-6.1668555227347, -3.7557094766312);
        glVertex2f(-6.202475777715, -3.7656039919035);
        glVertex2f(-6.249969451022, -3.7398782521956);
        glVertex2f(-6.2816318998933, -3.7062369002698);
        glVertex2f(-6.3172521548736, -3.6587432269628);
        glVertex2f(-6.3172521548736, -3.6053128444924);
        glVertex2f(-6.319231057928, -3.5597980742399);
        glVertex2f(-6.344956797636, -3.5182411100962);
        glVertex2f(-6.3726614403984, -3.4766841459526);
        glVertex2f(-6.3944293739974, -3.4371060848635);
        glVertex2f(-6.4221340167598, -3.3915913146109);
        glVertex2f(-6.4597331747945, -3.3520132535217);
        glVertex2f(-6.5, -3.3);
        glVertex2f(-6.5230580725372, -3.2629626160711);
        glVertex2f(-6.5487838122452, -3.2095322336008);
        glVertex2f(-6.5764884550076, -3.1640174633482);
        glVertex2f(-6.5923196794433, -3.1185026930957);
        glVertex2f(-6.6148690407736, -3.0553333670344);
        glVertex2f(-6.639136829248, -2.9916304222892);
        glVertex2f(-6.6816054590781, -3.0462329463565);
        glVertex2f(-6.7119401946711, -3.0887015761867);
        glVertex2f(-6.7544088245012, -3.1402706266947);
        glVertex2f(-6.8, -3.2);
        glVertex2f(-6.8277637305715, -3.272916152333);
        glVertex2f(-6.8360368402787, -3.3446164364619);
        glVertex2f(-6.8608561694002, -3.4080436108835);
        glVertex2f(-6.8884332017574, -3.482501598248);
        glVertex2f(-6.9049794211717, -3.5321402564911);
        glVertex2f(-6.9491026729433, -3.5790212114984);
        glVertex2f(-7, -3.6);
        glVertex2f(-7.0704416153152, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6865716376916);
        glVertex2f(-7.1311110865011, -3.7444834056418);
        glVertex2f(-7.1200802735582, -3.8079105800635);
        glVertex2f(-7.1145648670868, -3.8575492383065);
        glVertex2f(-7.1035340541439, -3.912703303021);
        glVertex2f(-7.0897455379652, -3.9816458839141);
        glVertex2f(-7.0594108023723, -4.0505884648071);
        glVertex2f(-6.9904682214792, -4.1305618586431);
        glVertex2f(-6.9353141567647, -4.1664120007075);
        glVertex2f(-6.8774023888145, -4.1939890330648);
        glVertex2f(-6.8112175111571, -4.2270814718935);
        glVertex2f(-6.7615788529141, -4.2491430977793);
        glVertex2f(-6.7091824914354, -4.2601739107222);
        glVertex2f(-6.6816054590781, -4.2601739107222);
        glVertex2f(-6.6337519252008, -4.2555968981756);
        glVertex2f(-6.5531197332974, -4.2415739082793);
        glVertex2f(-6.4759932888681, -4.2275509183831);
        glVertex2f(-6.4, -4.2);
        glVertex2f(-6.3287518949576, -4.1539302214279);
        glVertex2f(-6.2726599353727, -4.1083555042651);
        glVertex2f(-6.2380960326952, -4.0683761592356);
        glVertex2f(-6.2, -4);
        glVertex2f(-6.1826867471704, -3.9199584301513);
        glVertex2f(-6.1727922318981, -3.8546546293541);
        glVertex2f(-6.1628977166258, -3.7873719255026);
        glVertex2f(-6.1668555227347, -3.7557094766312);
        glVertex2f(-6.202475777715, -3.7656039919035);
        glVertex2f(-6.249969451022, -3.7398782521956);
        glVertex2f(-6.2816318998933, -3.7062369002698);
        glVertex2f(-6.3172521548736, -3.6587432269628);
        glVertex2f(-6.3172521548736, -3.6053128444924);
        glVertex2f(-6.319231057928, -3.5597980742399);
        glVertex2f(-6.344956797636, -3.5182411100962);
        glVertex2f(-6.3726614403984, -3.4766841459526);
        glVertex2f(-6.3944293739974, -3.4371060848635);
        glVertex2f(-6.4221340167598, -3.3915913146109);
        glVertex2f(-6.4597331747945, -3.3520132535217);
        glVertex2f(-6.5, -3.3);
        glVertex2f(-6.5230580725372, -3.2629626160711);
        glVertex2f(-6.5487838122452, -3.2095322336008);
        glVertex2f(-6.5764884550076, -3.1640174633482);
        glVertex2f(-6.5923196794433, -3.1185026930957);
        glVertex2f(-6.6148690407736, -3.0553333670344);
        glVertex2f(-6.639136829248, -2.9916304222892);
        glVertex2f(-6.6816054590781, -3.0462329463565);
        glVertex2f(-6.7119401946711, -3.0887015761867);
        glVertex2f(-6.7544088245012, -3.1402706266947);
        glVertex2f(-6.8, -3.2);
        glVertex2f(-6.8277637305715, -3.272916152333);
        glVertex2f(-6.8360368402787, -3.3446164364619);
        glVertex2f(-6.8608561694002, -3.4080436108835);
        glVertex2f(-6.8884332017574, -3.482501598248);
        glVertex2f(-6.9049794211717, -3.5321402564911);
        glVertex2f(-6.9491026729433, -3.5790212114984);
        glVertex2f(-7, -3.6);
        glVertex2f(-7.0704416153152, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6865716376916);
        glVertex2f(-7.1311110865011, -3.7444834056418);
        glVertex2f(-7.1200802735582, -3.8079105800635);
        glVertex2f(-7.1145648670868, -3.8575492383065);
        glVertex2f(-7.1035340541439, -3.912703303021);
        glVertex2f(-7.0897455379652, -3.9816458839141);
        glVertex2f(-7.0594108023723, -4.0505884648071);
        glVertex2f(-6.9904682214792, -4.1305618586431);
        glVertex2f(-6.9353141567647, -4.1664120007075);
        glVertex2f(-6.8774023888145, -4.1939890330648);
        glVertex2f(-6.8112175111571, -4.2270814718935);
        glVertex2f(-6.7615788529141, -4.2491430977793);
        glVertex2f(-6.7091824914354, -4.2601739107222);
        glVertex2f(-6.6816054590781, -4.2601739107222);
        glVertex2f(-6.6337519252008, -4.2555968981756);
        glVertex2f(-6.5531197332974, -4.2415739082793);
        glVertex2f(-6.4759932888681, -4.2275509183831);
        glVertex2f(-6.4, -4.2);
        glVertex2f(-6.3287518949576, -4.1539302214279);
        glVertex2f(-6.2726599353727, -4.1083555042651);
        glVertex2f(-6.2380960326952, -4.0683761592356);
        glVertex2f(-6.2, -4);
        glVertex2f(-6.1826867471704, -3.9199584301513);
        glVertex2f(-6.1727922318981, -3.8546546293541);
        glVertex2f(-6.1628977166258, -3.7873719255026);
        glVertex2f(-6.1668555227347, -3.7557094766312);
        glVertex2f(-6.202475777715, -3.7656039919035);
        glVertex2f(-6.249969451022, -3.7398782521956);
        glVertex2f(-6.2816318998933, -3.7062369002698);
        glVertex2f(-6.3172521548736, -3.6587432269628);
        glVertex2f(-6.3172521548736, -3.6053128444924);
        glVertex2f(-6.319231057928, -3.5597980742399);
        glVertex2f(-6.344956797636, -3.5182411100962);
        glVertex2f(-6.3726614403984, -3.4766841459526);
        glVertex2f(-6.3944293739974, -3.4371060848635);
        glVertex2f(-6.4221340167598, -3.3915913146109);
        glVertex2f(-6.4597331747945, -3.3520132535217);
        glVertex2f(-6.5, -3.3);
        glVertex2f(-6.5230580725372, -3.2629626160711);
        glVertex2f(-6.5487838122452, -3.2095322336008);
        glVertex2f(-6.5764884550076, -3.1640174633482);
        glVertex2f(-6.5923196794433, -3.1185026930957);
        glVertex2f(-6.6148690407736, -3.0553333670344);
        glVertex2f(-6.639136829248, -2.9916304222892);
        glVertex2f(-6.6816054590781, -3.0462329463565);
        glVertex2f(-6.7119401946711, -3.0887015761867);
        glVertex2f(-6.7544088245012, -3.1402706266947);
        glVertex2f(-6.8, -3.2);
        glVertex2f(-6.8277637305715, -3.272916152333);
        glVertex2f(-6.8360368402787, -3.3446164364619);
        glVertex2f(-6.8608561694002, -3.4080436108835);
        glVertex2f(-6.8884332017574, -3.482501598248);
        glVertex2f(-6.9049794211717, -3.5321402564911);
        glVertex2f(-6.9491026729433, -3.5790212114984);
        glVertex2f(-7, -3.6);
        glVertex2f(-7.0704416153152, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6865716376916);
        glVertex2f(-7.1311110865011, -3.7444834056418);
        glVertex2f(-7.1200802735582, -3.8079105800635);
        glVertex2f(-7.1145648670868, -3.8575492383065);
        glVertex2f(-7.1035340541439, -3.912703303021);
        glVertex2f(-7.0897455379652, -3.9816458839141);
        glVertex2f(-7.0594108023723, -4.0505884648071);
        glVertex2f(-6.9904682214792, -4.1305618586431);
        glVertex2f(-6.9353141567647, -4.1664120007075);
        glVertex2f(-6.8774023888145, -4.1939890330648);
        glVertex2f(-6.8112175111571, -4.2270814718935);
        glVertex2f(-6.7615788529141, -4.2491430977793);
        glVertex2f(-6.7091824914354, -4.2601739107222);
        glVertex2f(-6.6816054590781, -4.2601739107222);
        glVertex2f(-6.6337519252008, -4.2555968981756);
        glVertex2f(-6.5531197332974, -4.2415739082793);
        glVertex2f(-6.4759932888681, -4.2275509183831);
        glVertex2f(-6.4, -4.2);
        glVertex2f(-6.3287518949576, -4.1539302214279);
        glVertex2f(-6.2726599353727, -4.1083555042651);
        glVertex2f(-6.2380960326952, -4.0683761592356);
        glVertex2f(-6.2, -4);
        glVertex2f(-6.1826867471704, -3.9199584301513);
        glVertex2f(-6.1727922318981, -3.8546546293541);
        glVertex2f(-6.1628977166258, -3.7873719255026);
        glVertex2f(-6.1668555227347, -3.7557094766312);
        glVertex2f(-6.202475777715, -3.7656039919035);
        glVertex2f(-6.249969451022, -3.7398782521956);
        glVertex2f(-6.2816318998933, -3.7062369002698);
        glVertex2f(-6.3172521548736, -3.6587432269628);
        glVertex2f(-6.3172521548736, -3.6053128444924);
        glVertex2f(-6.319231057928, -3.5597980742399);
        glVertex2f(-6.344956797636, -3.5182411100962);
        glVertex2f(-6.3726614403984, -3.4766841459526);
        glVertex2f(-6.3944293739974, -3.4371060848635);
        glVertex2f(-6.4221340167598, -3.3915913146109);
        glVertex2f(-6.4597331747945, -3.3520132535217);
        glVertex2f(-6.5, -3.3);
        glVertex2f(-6.5230580725372, -3.2629626160711);
        glVertex2f(-6.5487838122452, -3.2095322336008);
        glVertex2f(-6.5764884550076, -3.1640174633482);
        glVertex2f(-6.5923196794433, -3.1185026930957);
        glVertex2f(-6.6148690407736, -3.0553333670344);
        glVertex2f(-6.639136829248, -2.9916304222892);
        glVertex2f(-6.6816054590781, -3.0462329463565);
        glVertex2f(-6.7119401946711, -3.0887015761867);
        glVertex2f(-6.7544088245012, -3.1402706266947);
        glVertex2f(-6.8, -3.2);
        glVertex2f(-6.8277637305715, -3.272916152333);
        glVertex2f(-6.8360368402787, -3.3446164364619);
        glVertex2f(-6.8608561694002, -3.4080436108835);
        glVertex2f(-6.8884332017574, -3.482501598248);
        glVertex2f(-6.9049794211717, -3.5321402564911);
        glVertex2f(-6.9491026729433, -3.5790212114984);
        glVertex2f(-7, -3.6);
        glVertex2f(-7.0704416153152, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6865716376916);
        glVertex2f(-7.1311110865011, -3.7444834056418);
        glVertex2f(-7.1200802735582, -3.8079105800635);
        glVertex2f(-7.1145648670868, -3.8575492383065);
        glVertex2f(-7.1035340541439, -3.912703303021);
        glVertex2f(-7.0897455379652, -3.9816458839141);
        glVertex2f(-7.0594108023723, -4.0505884648071);
        glVertex2f(-6.9904682214792, -4.1305618586431);
        glVertex2f(-6.9353141567647, -4.1664120007075);
        glVertex2f(-6.8774023888145, -4.1939890330648);
        glVertex2f(-6.8112175111571, -4.2270814718935);
        glVertex2f(-6.7615788529141, -4.2491430977793);
        glVertex2f(-6.7091824914354, -4.2601739107222);
        glVertex2f(-6.6816054590781, -4.2601739107222);
        glVertex2f(-6.6337519252008, -4.2555968981756);
        glVertex2f(-6.5531197332974, -4.2415739082793);
        glVertex2f(-6.4759932888681, -4.2275509183831);
        glVertex2f(-6.4, -4.2);
        glVertex2f(-6.3287518949576, -4.1539302214279);
        glVertex2f(-6.2726599353727, -4.1083555042651);
        glVertex2f(-6.2380960326952, -4.0683761592356);
        glVertex2f(-6.2, -4);
        glVertex2f(-6.1826867471704, -3.9199584301513);
        glVertex2f(-6.1727922318981, -3.8546546293541);
        glVertex2f(-6.1628977166258, -3.7873719255026);
        glVertex2f(-6.1668555227347, -3.7557094766312);
        glVertex2f(-6.202475777715, -3.7656039919035);
        glEnd();
        glPopMatrix();
    }
}
//AB010
void E_shuttleCock(){
    glLineWidth(5);
    glPushMatrix();
    glTranslatef(SCPosition,SCPositionY,0);
    glRotatef(SCAngle,0,0,1);
    glScalef(SCSize,SCSize,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-6.0f, -10.0f);
    glVertex2f(-3.5f, -10.0f);
    glVertex2f(-3.0f, -10.50f);
    glVertex2f(-6.5f, -10.50f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-6.0f, -10.0f);
    glVertex2f(-3.5f, -10.0f);
    glVertex2f(-3.5f, 3.0f);
    glVertex2f(-6.0f, 3.0f);
    glEnd();
    glPushMatrix();
    glTranslatef(-4.75f, 3.0f, 0.0f);
    glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/400;
            float r=1.25;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
	glFlush();
    glPopMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(6.0f, -10.0f);
    glVertex2f(3.5f, -10.0f);
    glVertex2f(3.0f, -10.50f);
    glVertex2f(6.5f, -10.50f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(6.0f, -10.0f);
    glVertex2f(3.5f, -10.0f);
    glVertex2f(3.5f, 3.0f);
    glVertex2f(6.0f, 3.0f);
    glEnd();
   glPushMatrix();
    glTranslatef(4.75f, 3.0f, 0.0f);
    glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/400;
            float r=1.25;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
	glFlush();
    E_fire(-11.8f,-20.0f);
    E_fire(-21.8f,-20.0f);
    glPopMatrix();
    glPopMatrix();

}
//AB011
void E_fuelTank() {
    glLineWidth(5);
    glPushMatrix();
    glTranslatef(FTPosition, FTPositionY, 0);
    glRotatef(FTAngle, 0, 0, 1);
    glScalef(FTSize, FTSize, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.778, 0.5, 0.002);
    glVertex2f(-4.0f, -10.f);
    glVertex2f(4.0f, -10.f);
    glVertex2f(2.5f, -8.0f);
    glVertex2f(-2.5f, -8.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.778, 0.5, 0.002);
    glVertex2f(-3.3f, -8.0f);
    glVertex2f(3.3f, -8.0f);
    glVertex2f(3.3f, 10.0f);
    glVertex2f(-3.3f, 10.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.778, 0.5, 0.002);
    glVertex2f(-3.3f, 10.0f);
    glVertex2f(3.3f, 10.0f);
    glVertex2f(0.0f, 13.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-3.3f, -8.0f);
    glVertex2f(3.3f, -8.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.2, 0.0);
    glVertex2f(-3.0f, -9.50f);
    glVertex2f(3.0f, -9.50f);
    glVertex2f(2.0f, -8.5f);
    glVertex2f(-2.0f, -8.5f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2.5f, -8.0f);
    glVertex2f(2.5f, -8.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-3.0f, -6.0f);
    glVertex2f(3.0f, -6.0f);
    glVertex2f(-3.0f, -7.0f);
    glVertex2f(3.0f, -7.0f);
    glVertex2f(-3.0f, -6.50f);
    glVertex2f(3.0f, -6.50f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.3, 0.0);
    glVertex2f(-1.0f, -8.0f);
    glVertex2f(1.0f, -8.0f);
    glVertex2f(0.0f, -7.0f);
    glEnd();
    E_fire(-13.8f, -15.5f);
    E_fire(-11.8f, -15.5f);
    E_fire(-9.8f, -15.5f);
    glPopMatrix();
}
void E_timer1(int value) {
    if (rightMouseClicked) {

        SCPositionY -= 0.80;
        SCAngle -= 5;
        glutPostRedisplay();
    }
    glutTimerFunc(20, E_timer1, 0);

}
void E_timer2(int value) {
    if (rightMouseClicked) {
        FTPositionY -= 0.80;
        glutPostRedisplay();
    }
    glutTimerFunc(20, E_timer2, 0);
}
//AB012
void E_Rocket(){
    glLineWidth(5);
    glPushMatrix();
    glTranslatef(RocketPosition,RocketPositionY,0);
    glRotatef(RocketAngle,0,0,1);
    glScalef(RocketSize,RocketSize,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.95f, 0.950f, 0.950f);
    glVertex2f(-0.5f, 6.0f);
    glVertex2f(0.5f, 6.0f);
    glVertex2f(0.0f, 7.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.70f, 0.70f, 0.70f);
    glVertex2f(-0.5f, 6.0f);
    glVertex2f(-2.0f, 4.0f);
    glVertex2f(-2.5f, 3.0f);
    glVertex2f(-2.5f, -4.0f);
    glVertex2f(2.5f, -4.0f);
    glVertex2f(2.5f, 3.0f);
    glVertex2f(2.0f, 4.0f);
    glVertex2f(0.5f, 6.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.40f, 0.40f, 0.40f);
    glVertex2f(-0.50f, 5.90f);
    glVertex2f(-1.5f, 4.0f);
    glVertex2f(-2.0f, -5.0f);
    glVertex2f(2.0f, -5.0f);
    glVertex2f(1.5f, 4.0f);
    glVertex2f(0.50f, 5.90f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.40f, 0.40f, 0.40f);
    glVertex2f(-1.0f, 2.0f);
    glVertex2f(-3.0f, -0.50f);
    glVertex2f(-3.0f, -1.50f);
    glVertex2f(-5.5f, -3.0f);
    glVertex2f(-5.5f, -5.0f);
    glVertex2f(-1.0f, -3.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.40f, 0.40f, 0.40f);
    glVertex2f(1.0f, 2.0f);
    glVertex2f(3.0f, -0.50f);
    glVertex2f(3.0f, -1.50f);
    glVertex2f(5.5f, -3.0f);
    glVertex2f(5.5f, -5.0f);
    glVertex2f(1.0f, -3.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.767, 0.975, 0.979);
    glVertex2f(-0.50f, 5.0f);
    glVertex2f(-1.2f, 4.0f);
    glVertex2f(-1.42f, 1.3f);
    glVertex2f(1.42f, 1.3f);
    glVertex2f(1.2f, 4.0f);
    glVertex2f(0.50f, 5.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.80f, 0.20f, 0.20f);
    glVertex2f(-1.58f, 1.3f);
    glVertex2f(-1.98f, 0.8f);
    glVertex2f(1.98f, 0.8f);
    glVertex2f(1.58f, 1.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.80f, 0.20f, 0.20f);
    glVertex2f(-5.5f, -5.0f);
    glVertex2f(-5.5f, -3.0f);
    glVertex2f(-6.2f, -3.0f);
    glVertex2f(-6.2f, -5.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.80f, 0.20f, 0.20f);
    glVertex2f(5.5f, -5.0f);
    glVertex2f(5.5f, -3.0f);
    glVertex2f(6.2f, -3.0f);
    glVertex2f(6.2f, -5.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(4.0, -5.0f);
    glVertex2f(4.0f, -1.0f);
    glVertex2f(5.4f, -1.0f);
    glVertex2f(5.4f, -5.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.937, 0.937, 0.949);
    glVertex2f(4.0f, -1.0f);
    glVertex2f(5.4f, -1.0f);
    glVertex2f(4.75f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-4.0, -5.0f);
    glVertex2f(-4.0f, -1.0f);
    glVertex2f(-5.4f, -1.0f);
    glVertex2f(-5.4f, -5.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.937, 0.937, 0.949);
    glVertex2f(-4.0f, -1.0f);
    glVertex2f(-5.4f, -1.0f);
    glVertex2f(-4.75f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(2.0, 0.7f);
    glVertex2f(2.0f, -3.5f);
    glVertex2f(3.4f, -4.0f);
    glVertex2f(3.4f, -.75f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex2f(2.0f, 0.0f);
    glVertex2f(3.4f, -0.75f);
    glVertex2f(2.f, 1.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(-2.0, 0.7f);
    glVertex2f(-2.0f, -3.5f);
    glVertex2f(-3.4f, -4.0f);
    glVertex2f(-3.4f, -.75f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(-3.4f, -0.75f);
    glVertex2f(-2.f, 1.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, -3.5f);
    glVertex2f(1.0f, -3.5f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, -3.5f);
    glVertex2f(-1.2f, -3.5f);
    glVertex2f(-1.2f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, -3.5f);
    glVertex2f(1.2f, -3.5f);
    glVertex2f(1.2f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.90f, 0.90f, 0.90f);
    glVertex2f(-0.50f, -1.0f);
    glVertex2f(-0.50f, -2.5f);
    glVertex2f(0.50f, -2.5f);
    glVertex2f(0.50f, -1.0f);
    glEnd();
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3f(0.50f, 0.50f, 0.50f);
    glVertex2f(-0.25f, -1.10f);
    glVertex2f(-0.85f, -1.45f);
    glVertex2f(-0.25f, -1.60f);
    glVertex2f(-0.85f, -1.95f);
    glVertex2f(-0.25f, -2.10f);
    glVertex2f(-0.85f, -2.45f);
    glVertex2f(0.25f, -1.10f);
    glVertex2f(0.85f, -1.45f);
    glVertex2f(0.25f, -1.60f);
    glVertex2f(0.85f, -1.95f);
    glVertex2f(0.25f, -2.10f);
    glVertex2f(0.85f, -2.45f);
    glEnd();
    glColor3f(0.80f, 0.8f, 0.80f);
    glPushMatrix();
    glTranslatef(0.0f, 0.50f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(2.0f, -0.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(-1.0f, -5.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(-1.0f, -0.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(2.0f, -0.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glPopMatrix();
    glBegin(GL_LINES);
    glColor4ub(0,0,0,0);
    glVertex2f(-3,5);
    glVertex2f(-3,5);
    glVertex2f(1.5,0);
    glVertex2f(-1.5,0);
    glVertex2f(1.5,-1);
    glVertex2f(-1.5,-1);
    glEnd();
    glPopMatrix();
}
//AB013
void E_RocketHolder(){
    glBegin(GL_POLYGON);
    glColor3f(0.843f, 0.771f, 0.863f);
    glVertex2f(-15.0f, -12.0f);
    glVertex2f(15.0f, -12.0f);
    glVertex2f(13.0f, -10.50f);
    glVertex2f(-13.0f, -10.50f);
    glEnd();
     glLineWidth(6.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-7.0f, 0.0f);
    glVertex2f(-5.5f, 0.0f);
    glVertex2f(-7.0f, -5.0f);
    glVertex2f(-5.5f, -5.0f);
    glVertex2f(-12.5f, -10.50f);
    glVertex2f(-12.5f, 8.0f);
    glVertex2f(-12.5f, 8.0f);
    glVertex2f(-11.0f, 8.0f);
    glVertex2f(-12.5f, 7.0f);
    glVertex2f(-11.0f, 7.0f);
    glVertex2f(-12.5f, 6.0f);
    glVertex2f(-11.0f, 6.0f);
    glVertex2f(-12.5f, 5.0f);
    glVertex2f(-11.0f, 5.0f);
    glVertex2f(-12.5f, 4.0f);
    glVertex2f(-11.0f, 4.0f);
    glVertex2f(-12.5f, 3.0f);
    glVertex2f(-11.0f, 3.0f);
    glVertex2f(-12.5f, 2.0f);
    glVertex2f(-11.0f, 2.0f);
    glVertex2f(-12.5f, 1.0f);
    glVertex2f(-11.0f, 1.0f);
    glVertex2f(-12.5f, 0.0f);
    glVertex2f(-11.0f, 0.0f);
    glVertex2f(-12.5f, -10.0f);
    glVertex2f(-11.0f, -10.0f);
    glVertex2f(-12.5f, -9.0f);
    glVertex2f(-11.0f, -9.0f);
    glVertex2f(-12.5f, -8.0f);
    glVertex2f(-11.0f, -8.0f);
    glVertex2f(-12.5f, -7.0f);
    glVertex2f(-11.0f, -7.0f);
    glVertex2f(-12.5f, -6.0f);
    glVertex2f(-11.0f, -6.0f);
    glVertex2f(-12.5f, -5.0f);
    glVertex2f(-11.0f, -5.0f);
    glVertex2f(-12.5f, -4.0f);
    glVertex2f(-11.0f, -4.0f);
    glVertex2f(-12.5f, -3.0f);
    glVertex2f(-11.0f, -3.0f);
    glVertex2f(-12.5f, -2.0f);
    glVertex2f(-11.0f, -2.0f);
    glVertex2f(-12.5f, -1.0f);
    glVertex2f(-11.0f, -1.0f);
    glVertex2f(-7.0f, -10.50f);
    glVertex2f(-7.0f, 8.0f);
    glVertex2f(-11.0f, -10.50f);
    glVertex2f(-11.0f, 8.0f);
    glVertex2f(-7.0f, 8.0f);
    glVertex2f(-11.0f, 8.0f);
    glVertex2f(-7.0f, 8.0f);
    glVertex2f(-11.0f, 4.0f);
    glVertex2f(-7.0f, 4.0f);
    glVertex2f(-11.0f, 0.0f);
    glVertex2f(-7.0f, 0.0f);
    glVertex2f(-11.0f, -4.0f);
    glVertex2f(-7.0f, -4.0f);
    glVertex2f(-11.0f, -8.0f);
    glVertex2f(-7.0f, 4.0f);
    glVertex2f(-11.0f, 8.0f);
    glVertex2f(-7.0f, 0.0f);
    glVertex2f(-11.0f, 4.0f);
    glVertex2f(-7.0f, -4.0f);
    glVertex2f(-11.0f, -0.0f);
    glVertex2f(-7.0f, -8.0f);
    glVertex2f(-11.0f, -4.0f);
    glVertex2f(-7.0f, -8.0f);
    glVertex2f(-11.0f, -8.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(7.0f, 0.0f);
    glVertex2f(5.5f, 0.0f);
    glVertex2f(7.0f, -5.0f);
    glVertex2f(5.5f, -5.0f);
    glVertex2f(7.0f, -10.50f);
    glVertex2f(7.0f, 8.0f);
    glVertex2f(11.0f, -10.50f);
    glVertex2f(11.0f, 8.0f);
    glVertex2f(7.0f, 8.0f);
    glVertex2f(11.0f, 8.0f);
    glVertex2f(7.0f, 8.0f);
    glVertex2f(11.0f, 4.0f);
    glVertex2f(7.0f, 4.0f);
    glVertex2f(11.0f, 0.0f);
    glVertex2f(7.0f, 0.0f);
    glVertex2f(11.0f, -4.0f);
    glVertex2f(7.0f, -4.0f);
    glVertex2f(11.0f, -8.0f);
    glVertex2f(7.0f, 4.0f);
    glVertex2f(11.0f, 8.0f);
    glVertex2f(7.0f, 0.0f);
    glVertex2f(11.0f, 4.0f);
    glVertex2f(7.0f, -4.0f);
    glVertex2f(11.0f, -0.0f);
    glVertex2f(7.0f, -8.0f);
    glVertex2f(11.0f, -4.0f);
    glVertex2f(7.0f, -8.0f);
    glVertex2f(11.0f, -8.0f);
    glVertex2f(12.5f, -10.50f);
    glVertex2f(12.5f, 8.0f);
    glVertex2f(12.5f, 8.0f);
    glVertex2f(11.0f, 8.0f);
    glVertex2f(12.5f, 7.0f);
    glVertex2f(11.0f, 7.0f);
    glVertex2f(12.5f, 6.0f);
    glVertex2f(11.0f, 6.0f);
    glVertex2f(12.5f, 5.0f);
    glVertex2f(11.0f, 5.0f);
    glVertex2f(12.5f, 4.0f);
    glVertex2f(11.0f, 4.0f);
    glVertex2f(12.5f, 3.0f);
    glVertex2f(11.0f, 3.0f);
    glVertex2f(12.5f, 2.0f);
    glVertex2f(11.0f, 2.0f);
    glVertex2f(12.5f, 1.0f);
    glVertex2f(11.0f, 1.0f);
    glVertex2f(12.5f, 0.0f);
    glVertex2f(11.0f, 0.0f);
    glVertex2f(12.5f, -10.0f);
    glVertex2f(11.0f, -10.0f);
    glVertex2f(12.5f, -9.0f);
    glVertex2f(11.0f, -9.0f);
    glVertex2f(12.5f, -8.0f);
    glVertex2f(11.0f, -8.0f);
    glVertex2f(12.5f, -7.0f);
    glVertex2f(11.0f, -7.0f);
    glVertex2f(12.5f, -6.0f);
    glVertex2f(11.0f, -6.0f);
    glVertex2f(12.5f, -5.0f);
    glVertex2f(11.0f, -5.0f);
    glVertex2f(12.5f, -4.0f);
    glVertex2f(11.0f, -4.0f);
    glVertex2f(12.5f, -3.0f);
    glVertex2f(11.0f, -3.0f);
    glVertex2f(12.5f, -2.0f);
    glVertex2f(11.0f, -2.0f);
    glVertex2f(12.5f, -1.0f);
    glVertex2f(11.0f, -1.0f);
    glEnd();
     glColor3f(0.361f, 0.369f, 0.263f);
    glBegin(GL_POLYGON);
    glVertex2f(-25.0f, -12.0f);
    glVertex2f(25.0f, -12.0f);
    glVertex2f(25.0f, -20.0f);
    glVertex2f(-25.0f, -20.0f);
    glEnd();
    //I_AnimatedTextAdder("In the year 2223, Earth stood on the edge of ruin.                                                                  ", -30.0, 15.0);

}
//AB014
void E_sun(){
    E_Circle(4.5,35,0,32,255,255,51,255);
}
//AB015
void E_Cloud(){
glPushMatrix();
glTranslatef(5,15,0);
E_Circle(2,30,2.5,-1,255);
E_Circle(2,30,-1,-2,255);
E_Circle(2,30,1,0,255);
E_Circle(2.3,35,-2.5,1,255);
glPopMatrix();
glPushMatrix();
glTranslatef(20,25,0);
glScalef(1.0,1.0,0);
E_Circle(2,30,2.5,-1,255);
E_Circle(2,30,-1,-2,255);
E_Circle(2,30,1,0,255);
E_Circle(2.3,35,-2.5,1,255);
glPopMatrix();
glPushMatrix();
glTranslatef(-20,35,0);
glScalef(1.0,1.0,0);
E_Circle(2.5,30,2.5,-1,255);
E_Circle(2.5,30,-1,-2,255);
E_Circle(2.5,30,1,0,255);
E_Circle(2.8,35,-2.5,1,255);
glPopMatrix();
glPushMatrix();
glTranslatef(-20,9,0);
glScalef(1.0,1.0,0);
E_Circle(1.5,30,-2.2,-1,255);
E_Circle(1.5,30,-1.2,-1.2,255);
E_Circle(1.5,30,1.2,-1.6,255);
E_Circle(1.8,35,2.2,-0.7,255);
glPopMatrix();
glPushMatrix();
glTranslatef(-15,18,0);
glScalef(0.50,0.50,0);
E_Circle(1.5,30,-2.2,-1,255);
E_Circle(1.5,30,-1.2,-1.2,255);
E_Circle(1.5,30,1.2,-1.6,255);
E_Circle(1.8,35,2.2,-0.7,255);
glPopMatrix();
}
//AB016
void E_bigMeteor1(){
glPushMatrix();
            glTranslatef(BigMeteorPosition,150,0);
            glScalef(18.0f,18.0f,0.0);
            glBegin(GL_POLYGON);
            glColor3ub(197,124,22);
            glVertex2f(-0.16, 0.45);
            glVertex2f(-0.12, 0.45);
            glVertex2f(-0.06, 0.41);
            glVertex2f(-0.04, 0.39);
            glVertex2f(-0.03, 0.38);
            glVertex2f(-0.01, 0.4);
            glVertex2f(0.03, 0.39);
            glVertex2f(0.05, 0.36);
            glVertex2f(0.05, 0.32);
            glVertex2f(0.06, 0.28);
            glVertex2f(0.06, 0.26);
            glVertex2f(0.07, 0.22);
            glVertex2f(0.05, 0.18);
            glVertex2f(0.05, 0.14);
            glVertex2f(0.04, 0.13);
            glVertex2f(0.02, 0.11);
            glVertex2f(-0.08, 0.09);
            glVertex2f(-0.11, 0.11);
            glVertex2f(-0.11, 0.09);
            glVertex2f(-0.18, 0.08);
            glVertex2f(-0.21, 0.02);
            glVertex2f(-0.26, 0.05);
            glVertex2f(-0.27, 0.05);
            glVertex2f(-0.3, 0.11);
            glVertex2f(-0.36, 0.11);
            glVertex2f(-0.36, 0.15);
            glVertex2f(-0.41, 0.18);
            glVertex2f(-0.41, 0.2);
            glVertex2f(-0.39, 0.23);
            glVertex2f(-0.42, 0.26);
            glVertex2f(-0.39, 0.29);
            glVertex2f(-0.39, 0.29);
            glVertex2f(-0.39, 0.32);
            glVertex2f(-0.38, 0.34);
            glVertex2f(-0.38, 0.37);
            glVertex2f(-0.35, 0.37);
            glVertex2f(-0.34, 0.39);
            glVertex2f(-0.31, 0.39);
            glVertex2f(-0.3, 0.39);
            glVertex2f(-0.3, 0.41);
            glVertex2f(-0.28, 0.42);
            glVertex2f(-0.25, 0.43);
            glVertex2f(-0.23, 0.45);
            glVertex2f(-0.19, 0.45);
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(197,124,22);
            glVertex2f(-0.05, 0.3);
            glVertex2f(-0.02, 0.26);
            glVertex2f(-0.04, 0.23);
            glVertex2f(-0.06, 0.22);
            glVertex2f(-0.09, 0.24);
            glVertex2f(-0.09, 0.3);
            glEnd();
glPopMatrix();
}
//AB017
void E_bigMeteor2(){
            glPushMatrix();
            glTranslatef(BigMeteorPosition,190,0);
            glScalef(10.0f,10.0f,0.0);
            glBegin(GL_POLYGON);
            glColor3ub(96,82,82);
            glVertex2f(-0.14, 0.46);
            glVertex2f(-0.06, 0.5);
            glVertex2f(-0.01, 0.5);
            glVertex2f(0.05, 0.48);
            glVertex2f(0.14, 0.48);
            glVertex2f(0.15, 0.5);
            glVertex2f(0.22, 0.5);
            glVertex2f(0.25, 0.44);
            glVertex2f(0.32, 0.4);
            glVertex2f(0.38, 0.36);
            glVertex2f(0.39, 0.3);
            glVertex2f(0.41, 0.28);
            glVertex2f(0.38, 0.23);
            glVertex2f(0.34, 0.18);
            glVertex2f(0.38, 0.13);
            glVertex2f(0.3, 0.09);
            glVertex2f(0.36, -0.03);
            glVertex2f(0.33, -0.04);
            glVertex2f(0.27, -0.04);
            glVertex2f(0.23, 0.02);
            glVertex2f(0.23, 0.09);
            glVertex2f(0.21, 0.09);
            glVertex2f(0.18, 0.08);
            glVertex2f(0.18, 0.07);
            glVertex2f(0.17, 0.04);
            glVertex2f(0.2, 0);
            glVertex2f(0.23, -0.01);
            glVertex2f(0.23, -0.01);
            glVertex2f(0.23, -0.01);
            glVertex2f(0.2, 0.09);
            glVertex2f(0.11, 0.1);
            glVertex2f(0.12, 0.05);
            glVertex2f(0.12, 0.05);
            glVertex2f(0.18, 0.05);
            glVertex2f(0.08, 0.01);
            glVertex2f(-0.07, 0.08);
            glVertex2f(-0.14, 0.07);
            glVertex2f(-0.14, 0.14);
            glVertex2f(-0.22, 0.14);
            glVertex2f(-0.19, 0.2);
            glVertex2f(-0.19, 0.2);
            glVertex2f(-0.19, 0.2);
            glVertex2f(-0.22, 0.18);
            glVertex2f(-0.23, 0.21);
            glVertex2f(-0.23, 0.25);
            glVertex2f(-0.23, 0.25);
            glVertex2f(-0.22, 0.26);
            glVertex2f(-0.21, 0.26);
            glVertex2f(-0.22, 0.29);
            glVertex2f(-0.22, 0.29);
            glVertex2f(-0.22, 0.29);
            glVertex2f(-0.19, 0.33);
            glVertex2f(-0.18, 0.33);
            glVertex2f(-0.18, 0.36);
            glVertex2f(-0.18, 0.37);
            glVertex2f(-0.13, 0.38);
            glVertex2f(-0.15, 0.42);
            glVertex2f(-0.15, 0.42);
            glVertex2f(-0.12, 0.46);
            glVertex2f(-0.12, 0.48);
            glEnd();
            glPopMatrix();
}
//AB018
void E_bigMeteor3(){
            glPushMatrix();
            glTranslatef(BigMeteorPosition,140,0);
            glScalef(20.0f,20.0f,0.0);
            glBegin(GL_POLYGON);
            glColor3ub(192,141,114);
            glVertex2f(-0.21, 0.24);
            glVertex2f(-0.16, 0.29);
            glVertex2f(-0.12, 0.28);
            glVertex2f(-0.09, 0.31);
            glVertex2f(-0.05, 0.31);
            glVertex2f(-0.02, 0.28);
            glVertex2f(0.02, 0.27);
            glVertex2f(0.05, 0.25);
            glVertex2f(0.05, 0.21);
            glVertex2f(0.08, 0.18);
            glVertex2f(0.08, 0.13);
            glVertex2f(0.11, 0.07);
            glVertex2f(0.07, 0.02);
            glVertex2f(0.07, -0.02);
            glVertex2f(0.05, -0.06);
            glVertex2f(-0.03, -0.06);
            glVertex2f(-0.05, -0.11);
            glVertex2f(-0.09, -0.12);
            glVertex2f(-0.14, -0.15);
            glVertex2f(-0.17, -0.14);
            glVertex2f(-0.19, -0.11);
            glVertex2f(-0.23, -0.11);
            glVertex2f(-0.23, -0.08);
            glVertex2f(-0.27, -0.06);
            glVertex2f(-0.27, -0.04);
            glVertex2f(-0.26, 0);
            glVertex2f(-0.29, 0);
            glVertex2f(-0.33, 0.03);
            glVertex2f(-0.31, 0.08);
            glVertex2f(-0.39, 0.09);
            glVertex2f(-0.37, 0.13);
            glVertex2f(-0.37, 0.17);
            glVertex2f(-0.33, 0.17);
            glVertex2f(-0.33, 0.21);
            glVertex2f(-0.31, 0.21);
            glVertex2f(-0.3, 0.22);
            glVertex2f(-0.25, 0.23);
            glVertex2f(-0.25, 0.25);
            glEnd();
            glPopMatrix();
}
//AB019
void E_bigMeteor4(){
            glPushMatrix();
            glTranslatef(BigMeteorPosition,165,0);
            glScalef(20.0f,20.0f,0.0);
            glBegin(GL_POLYGON);
            glColor3ub(192,141,114);
            glVertex2f(-0.21, 0.24);
            glVertex2f(-0.16, 0.29);
            glVertex2f(-0.12, 0.28);
            glVertex2f(-0.09, 0.31);
            glVertex2f(-0.05, 0.31);
            glVertex2f(-0.02, 0.28);
            glVertex2f(0.02, 0.27);
            glVertex2f(0.05, 0.25);
            glVertex2f(0.05, 0.21);
            glVertex2f(0.08, 0.18);
            glVertex2f(0.08, 0.13);
            glVertex2f(0.11, 0.07);
            glVertex2f(0.07, 0.02);
            glVertex2f(0.07, -0.02);
            glVertex2f(0.05, -0.06);
            glVertex2f(-0.03, -0.06);
            glVertex2f(-0.05, -0.11);
            glVertex2f(-0.09, -0.12);
            glVertex2f(-0.14, -0.15);
            glVertex2f(-0.17, -0.14);
            glVertex2f(-0.19, -0.11);
            glVertex2f(-0.23, -0.11);
            glVertex2f(-0.23, -0.08);
            glVertex2f(-0.27, -0.06);
            glVertex2f(-0.27, -0.04);
            glVertex2f(-0.26, 0);
            glVertex2f(-0.29, 0);
            glVertex2f(-0.33, 0.03);
            glVertex2f(-0.31, 0.08);
            glVertex2f(-0.39, 0.09);
            glVertex2f(-0.37, 0.13);
            glVertex2f(-0.37, 0.17);
            glVertex2f(-0.33, 0.17);
            glVertex2f(-0.33, 0.21);
            glVertex2f(-0.31, 0.21);
            glVertex2f(-0.3, 0.22);
            glVertex2f(-0.25, 0.23);
            glVertex2f(-0.25, 0.25);
            glEnd();
            glPopMatrix();
}
//AB020
void E_smallMeteor1(){
    glPushMatrix();
    glTranslatef(SmallMeteorPosition,180,0);
    glScalef(10.0f,10.0f,0.0);
            glBegin(GL_POLYGON);
            glColor3ub(168,79,16);
            glVertex2f(0.41, 0.81);
            glVertex2f(0.48, 0.91);
            glVertex2f(0.56, 0.86);
            glVertex2f(0.6, 0.77);
            glVertex2f(0.58, 0.69);
            glVertex2f(0.59, 0.63);
            glVertex2f(0.54, 0.57);
            glVertex2f(0.47, 0.55);
            glVertex2f(0.42, 0.56);
            glVertex2f(0.39, 0.64);
            glVertex2f(0.34, 0.64);
            glVertex2f(0.29, 0.74);
            glVertex2f(0.36, 0.79);
            glEnd();
    glPopMatrix();
}
//AB021
void E_smallMeteor2(){
        glPushMatrix();
        glTranslatef(SmallMeteorPosition,180,0);
        glScalef(8.0f,18.0f,0.0);
          glBegin(GL_POLYGON);
            glColor3ub(120,120,120);
            glVertex2f(-0.3, 0.27);
            glVertex2f(-0.2, 0.29);
            glVertex2f(-0.11, 0.3);
            glVertex2f(-0.07, 0.27);
            glVertex2f(0.04, 0.29);
            glVertex2f(0.06, 0.31);
            glVertex2f(0.08, 0.31);
            glVertex2f(0.14, 0.29);
            glVertex2f(0.15, 0.29);
            glVertex2f(0.18, 0.3);
            glVertex2f(0.21, 0.32);
            glVertex2f(0.3, 0.28);
            glVertex2f(0.3, 0.23);
            glVertex2f(0.25, 0.18);
            glVertex2f(0.12, 0.19);
            glVertex2f(0.16, 0.14);
            glVertex2f(0.15, 0.11);
            glVertex2f(0.1, 0.11);
            glVertex2f(0.05, 0.15);
            glVertex2f(0.05, 0.14);
            glVertex2f(0.02, 0.12);
            glVertex2f(0, 0.1);
            glVertex2f(-0.07, 0.1);
            glVertex2f(-0.09, 0.14);
            glVertex2f(-0.09, 0.14);
            glVertex2f(-0.09, 0.14);
            glVertex2f(-0.12, 0.07);
            glVertex2f(-0.14, 0.04);
            glVertex2f(-0.15, 0.04);
            glVertex2f(-0.17, 0.04);
            glVertex2f(-0.2, 0.05);
            glVertex2f(-0.22, 0.06);
            glVertex2f(-0.23, 0.06);
            glVertex2f(-0.23, 0.06);
            glVertex2f(-0.25, 0.07);
            glVertex2f(-0.24, 0.05);
            glVertex2f(-0.25, 0.04);
            glVertex2f(-0.32, 0.04);
            glVertex2f(-0.32, 0.05);
            glVertex2f(-0.32, 0.05);
            glVertex2f(-0.31, 0.06);
            glVertex2f(-0.34, 0.1);
            glVertex2f(-0.36, 0.1);
            glVertex2f(-0.41, 0.12);
            glVertex2f(-0.41, 0.14);
            glVertex2f(-0.39, 0.17);
            glVertex2f(-0.41, 0.17);
            glVertex2f(-0.41, 0.24);
            glVertex2f(-0.41, 0.24);
            glVertex2f(-0.36, 0.22);
            glVertex2f(-0.37, 0.23);
            glVertex2f(-0.34, 0.28);
            glVertex2f(-0.34, 0.27);
            glVertex2f(-0.36, 0.3);
            glVertex2f(-0.31, 0.3);
            glVertex2f(-0.31, 0.29);
            glVertex2f(-0.22, 0.29);
            glEnd();
glPopMatrix();

}
//AB022
void E_smallMeteor3(){
        glPushMatrix();
        glTranslatef(SmallMeteorPosition,175,0);
        glScalef(6.0f,10.0f,0.0);
          glBegin(GL_POLYGON);
            glColor3ub(120,170,120);
            glVertex2f(-0.3, 0.27);
            glVertex2f(-0.2, 0.29);
            glVertex2f(-0.11, 0.3);
            glVertex2f(-0.07, 0.27);
            glVertex2f(0.04, 0.29);
            glVertex2f(0.06, 0.31);
            glVertex2f(0.08, 0.31);
            glVertex2f(0.14, 0.29);
            glVertex2f(0.15, 0.29);
            glVertex2f(0.18, 0.3);
            glVertex2f(0.21, 0.32);
            glVertex2f(0.3, 0.28);
            glVertex2f(0.3, 0.23);
            glVertex2f(0.25, 0.18);
            glVertex2f(0.12, 0.19);
            glVertex2f(0.16, 0.14);
            glVertex2f(0.15, 0.11);
            glVertex2f(0.1, 0.11);
            glVertex2f(0.05, 0.15);
            glVertex2f(0.05, 0.14);
            glVertex2f(0.02, 0.12);
            glVertex2f(0, 0.1);
            glVertex2f(-0.07, 0.1);
            glVertex2f(-0.09, 0.14);
            glVertex2f(-0.09, 0.14);
            glVertex2f(-0.09, 0.14);
            glVertex2f(-0.12, 0.07);
            glVertex2f(-0.14, 0.04);
            glVertex2f(-0.15, 0.04);
            glVertex2f(-0.17, 0.04);
            glVertex2f(-0.2, 0.05);
            glVertex2f(-0.22, 0.06);
            glVertex2f(-0.23, 0.06);
            glVertex2f(-0.23, 0.06);
            glVertex2f(-0.25, 0.07);
            glVertex2f(-0.24, 0.05);
            glVertex2f(-0.25, 0.04);
            glVertex2f(-0.32, 0.04);
            glVertex2f(-0.32, 0.05);
            glVertex2f(-0.32, 0.05);
            glVertex2f(-0.31, 0.06);
            glVertex2f(-0.34, 0.1);
            glVertex2f(-0.36, 0.1);
            glVertex2f(-0.41, 0.12);
            glVertex2f(-0.41, 0.14);
            glVertex2f(-0.39, 0.17);
            glVertex2f(-0.41, 0.17);
            glVertex2f(-0.41, 0.24);
            glVertex2f(-0.41, 0.24);
            glVertex2f(-0.36, 0.22);
            glVertex2f(-0.37, 0.23);
            glVertex2f(-0.34, 0.28);
            glVertex2f(-0.34, 0.27);
            glVertex2f(-0.36, 0.3);
            glVertex2f(-0.31, 0.3);
            glVertex2f(-0.31, 0.29);
            glVertex2f(-0.22, 0.29);
            glEnd();
        glPopMatrix();
}
//AB023
void E_Stars(){
glPushMatrix();
glRotatef(StarsAngle,0,0,1);
glScalef(1.5,1.5,0);
glPushMatrix();
glTranslatef(StarsPosition,125,0);
E_CirclePoints(30,20,0,0,6,255,255,255);
E_CirclePoints(20,10,0,0,6,255,255,255);
E_CirclePoints(10,5,0,0,5,255,255,255);
E_CirclePoints(5,5,0,0,5,255,255,255);
glPopMatrix();
glPushMatrix();
glTranslatef(StarsPosition+65,125,0);
E_CirclePoints(30,20,0,0,5,255,255,255);
E_CirclePoints(20,10,0,0,5,255,255,255);
E_CirclePoints(10,5,0,0,5,255,255,255);
E_CirclePoints(5,5,0,0,5,255,255,255);
E_CirclePoints(25,15,0,0,9,255,0,255);
E_CirclePoints(12,5,0,0,5,255,0,0);
E_CirclePoints(13,5,0,0,8,0,0,255);
E_CirclePoints(16,5,0,0,8,0,0,255);
glPopMatrix();
glPopMatrix();
}
void E_GradientEffect(){
    glBegin(GL_POLYGON);

    // Define gradient colors with alpha values
    glColor4ub(15, 15, 15, 80);
    glVertex2f(-50, -30);
    glColor4ub(20, 20, 20, 80);
    glVertex2f(-50, 150);
    glColor4ub(0, 0, 0, 80);
    glVertex2f(-50, 210);
    glColor4ub(0, 0, 0, 80);
    glVertex2f(50, 210);
    glColor4ub(20, 20, 20, 80);
    glVertex2f(50, 150);
    glColor4ub(195, 195, 195, 80);
    glVertex2f(50, -30);

    glEnd();
}
int controlcount=0;
void E_ControlsInfo(){
    glColor3ub(55,55,55);
    //E_DrawTextStroke(-30,15,0,0.015,5,"Press Mouse Left To Launch Rocket");
    if(text1) E_DrawTextStroke(-20,15,0,0.007,2,"Governments, scientists, and ordinary people united to escape the devastation.", GLUT_STROKE_MONO_ROMAN);
    if(text2) E_DrawTextStroke(-25,15,0,0.007,2,"Onboard the Hopebringer, peoples are prepared to face the hardships of space travel for the hope of NEW BEGINING", GLUT_STROKE_MONO_ROMAN);
    if(text3) E_DrawTextStroke(-25,15,0,0.007,2,"Ready to depart, they are leaving behind a crumbling Earth, memories of which will be blurred over time.", GLUT_STROKE_MONO_ROMAN);
    if(text4) E_DrawTextStroke(-20,15,0,0.007,2,"Left click on mouse to ignite the space craft", GLUT_STROKE_MONO_ROMAN);

    glColor3ub(255,255,255);
    E_DrawTextStroke(-20,90,0,0.007,2,"With heavy hearts, they bid a final farewell to Mother Earth,");
    E_DrawTextStroke(-20,86,0,0.007,2,"sorrowful gazes lingering on the once vibrant but now doomed planet.");
    if(controlcount>=1500){
        E_DrawTextStroke(-18,180,0,0.007,2,"                                                 ");
        E_DrawTextStroke(-18,175,0,0.007,2,"                                                 ");
    }
    else{
        E_DrawTextStroke(-14,170,0,0.007,2,"Press W & S To Control Rocket");
        E_DrawTextStroke(-14,168,0,0.007,2,"Press Q & A To Control Speed");
    }if(controlcount>1700){
        E_DrawTextStroke(-22,170,0,0.007,2,"            The shared dream of a new home fueled their journey,");
        E_DrawTextStroke(-22,168,0,0.007,2,"and the pioneers clung to hope as they approached an unknown, promising exoplanet.");
    }

    std::cout<<controlcount++<<std::endl;
}
void E_PrintFunction(){
    glPushMatrix();
    glTranslatef(0,BackgroundPosition,0);
    E_Sky();
    E_Cloud();
    E_sun();
    E_buildingtype1(5.0, -12.0, 20.0, 12.0, 0.9, 0.9, 0.9, 0.95);
    E_buildingtype1(-18.0, -12.0, 17.0, 12.0, 0.9, 0.9, 0.9, 0.90);
    E_buildingtype1(-12.0, -12.0, 18.0, 6.0, 0.9, 0.9, 0.9, 0.90);
    E_buildingtype1(0.0, -12.0, 15.0, 11.0, 0.9, 0.9, 0.9, 0.90);
    E_buildingtype1(-19.0, -12.0, 16.0, 16.0, 0.92, 0.92, 0.92, 0.95);
    E_buildingtype1(16.0, -12.0, 19.0, 6.0, 0.9, 0.9, 0.9, 0.95);
    E_buildingtype1(0.0, -12.0, 14.0, 6.0, 0.9, 0.9, 0.9, 0.95);
    E_buildingtype2(-25.0, -12.0, 14.0, 11.0, 0.55, 0.5, 0.5, 0.90);
    E_buildingtype2(12.0, -12.0, 13.0, 11.0, 0.55, 0.5, 0.5, 0.99);
    E_buildingtype1(-8.0, -12.0, 19.0, 16.0, 0.8, 0.8, 0.8, 1.0);
    E_buildingtype1(-18.0, -12.0, 13.0, 12.0, 0.3, 0.3, 0.3, 1.0);
    E_buildingtype1(-20.0, -12.0, 7.0, 6.0, 0.7, 0.7, 0.7, 1.0);
    E_buildingtype1(0.0, -12.0, 17.0, 11.0, 0.7, 0.7, 0.7, 1.0);
    E_buildingtype1(-10.0, -12.0, 12.0, 16.0, 0.72, 0.72, 0.72, 1.0);
    E_buildingtype1(20.0, -12.0, 18.0, 6.0, 0.7, 0.7, 0.7, 1.0);
    E_buildingtype1(0.0, -12.0, 18.0, 6.0, 0.5, 0.5, 0.5, 1.0);
    E_workshopBuilding(8.0, -12.0, 10.0, 20.0, 0.99, 0.99, 0.99, 1.0);
    E_buildingtype1(-06.0, -12.0, 8.0, 13.0, 0.7, 0.7, 0.7, 1.0);
    E_RocketHolder();
    E_Stars();
    glPopMatrix();
    E_shuttleCock();
    E_fuelTank();
    E_Rocket();
    glPushMatrix();
    glTranslatef(0,BackgroundPosition,0);
    E_bigMeteor1();
    E_bigMeteor2();
    E_bigMeteor3();
    E_bigMeteor4();
    E_smallMeteor1();
    E_smallMeteor2();
    E_smallMeteor3();
    car();
    E_ControlsInfo();
    glPopMatrix();
}
//AAB01
void E_BigMeteorMoveAnimation(int value){
   if(BigMeteorPosition > -195){BigMeteorPosition -= BigMeteorMoveSpeed;}
   else{BigMeteorPosition = 110;}
   glutPostRedisplay();
   glutTimerFunc(10,E_BigMeteorMoveAnimation,0);
}
//AAB02
void E_SmallMeteorMoveAnimation(int value){
   if(SmallMeteorPosition > -195){SmallMeteorPosition -= SmallMeteorMoveSpeed;}
   else{SmallMeteorPosition = 110;}
   glutPostRedisplay();
   glutTimerFunc(10,E_SmallMeteorMoveAnimation,0);

}
//AAB03
void E_StarsAnimation(int value){
    if(StarsPosition > -65){
    StarsPosition-=StarsMoveSpeed;
    StarsAngle = 0;
    }
    else
    {
      StarsPosition = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(10,E_StarsAnimation, 0);
}
//AAB04
void E_detachFuelTank(int value) {
    fuelTankDetached = true;
    }
//AAB05
void E_RocketInGalaxyAnimation(int value){
        FTSize = 1.2;
       SCSize = 1.2;

if(RocketAngle>-90)
    {
        RocketAngle -= RocketSpinSpeed;
    }
else
    {
        RocketAngle = -90;
    }

if(RocketAngle == -90)
    {
    if(RocketPosition > -20)
    {
        RocketPosition -= RocketMoveSpeed;
    }
    else {
            RocketPosition = -20;
         }
    if(RocketSize > 0.7)
    {
         RocketSize -= RocketSizeChanger;
         }
    else {
            RocketSize = 0.7;
         }
    }

    if(!(RocketPosition == -20)){
        glutPostRedisplay();
        glutTimerFunc(500,E_RocketInGalaxyAnimation, 0);
    }
    else{
        isProcessing = false;
        canRocketControl = true;
    }
    if(!(FTPosition == -20&&SCPosition == -20)){
        glutPostRedisplay();
        glutTimerFunc(500,E_RocketInGalaxyAnimation, 0);
    }else{
        isProcessing = false;
        glutTimerFunc(detachmentTime, E_detachFuelTank, 0);
    }

}
void E_BackgroundTowardGround(int);
//AAB06
void E_RocketInGround(int value){

    if(RocketPosition < 0)
        RocketPosition += RocketMoveSpeed;
    else
        RocketPosition = 0;
    if(RocketSize < 1)
        RocketSize += RocketSizeChanger;
    else
        RocketSize = 1;



    if(RocketPositionY < 0)
        RocketPositionY += RocketMoveSpeed;
    else if(RocketPositionY > 0)
        RocketPositionY -= RocketMoveSpeed;
    else
        RocketPositionY = 0;

    if((RocketPosition == 0)){
        BigMeteorMoveSpeed = 0.15;
        SmallMeteorMoveSpeed = 0.065;
        if(RocketAngle < 0)
            RocketAngle += RocketSpinSpeed;
        else
            RocketAngle = 0;
    }
    if(!(RocketAngle == 0)){
        glutPostRedisplay();
        glutTimerFunc(10,E_RocketInGround, 0);
    }
}
//AAB07
void E_BackgroundTowardGalaxy(int value){

    if(BackgroundPosition > FinalDestination){ BackgroundPosition -=BackgroundMoveSpeed;}
    else{BackgroundPosition = FinalDestination;}

    glutPostRedisplay();

    if(BackgroundPosition == FinalDestination){
        isRocketinGalaxy = true;
        glutTimerFunc(10,E_RocketInGalaxyAnimation,0);
    }
    if(!isRocketinGalaxy){
        glutTimerFunc(10, E_BackgroundTowardGalaxy, 0);
    }
}
void E_UpdateFunctions(){
 glutTimerFunc(10,E_BigMeteorMoveAnimation,0);
 glutTimerFunc(10,E_SmallMeteorMoveAnimation,0);
 glutTimerFunc(100,E_detachFuelTank,0);
 glutTimerFunc(3000, E_scale, 0);
 glutTimerFunc(10,E_StarsAnimation,0);

}
void E_mouse(int button,int state,int x,int y){
    switch(button)
    {
        if(!isProcessing)
        {
            case GLUT_LEFT_BUTTON:
            {
                if(state==GLUT_DOWN && !isProcessing && !isRocketinGalaxy && text4){
                    isProcessing = true;        ///Start Process - Rocket toward Galaxy
                    FinalDestination = -180;
                    glutTimerFunc(10, E_BackgroundTowardGalaxy, 0);
                    rightMouseClicked = true;
                    IsFire = true;
                    glutTimerFunc(8000, E_timer1, 0);
                    glutTimerFunc(12000, E_timer2, 0);
                    text1=false;
                    text2=false;
                    text3=false;
                    text4=false;


                }
            } break;

            case GLUT_RIGHT_BUTTON:
            {
                if(state==GLUT_DOWN && !isProcessing && isRocketinGalaxy){
                    isProcessing = true;
                    canRocketControl = false;
                    FinalDestination = 0;
                }
            } break;

            default:
                break;
        }
    }
}
void E_keyboard(unsigned char key, int x, int y){
    if(canRocketControl)
    {
        if(key=='w' || key=='W')
        {
            RocketPositionY+=RocketMoveSpeed*5;
            FTPositionY+=FTMoveSpeed*5;
            SCPositionY+=SCMoveSpeed*5;
        }
        if(key=='s' || key=='S')
        {
            RocketPositionY-=RocketMoveSpeed*5;
            FTPositionY-=FTMoveSpeed*5;
            SCPositionY-=SCMoveSpeed*5;
        }
        if(key=='q' || key=='Q'){
           BigMeteorMoveSpeed = 1;
           SmallMeteorMoveSpeed = 0.55;
           StarsMoveSpeed=0.5;
        }
        if((key=='a' || key=='A')&& !text1 && !text2 && !text3 && !text4){
           BigMeteorMoveSpeed = 0.085;
           SmallMeteorMoveSpeed = 0.35;
           StarsMoveSpeed=0.05;
        }
        else if(key=='a' || key=='A') {
            if(text2){
                text2=false;
                text1=true;
            }
            else if(text3){
                text3=false;
                text2=true;
            }
            else if(text4){
                text3=true;
                text4=false;
            }
        }
        if(key=='d' || key=='D'){

            if(text1){
                text1=false;
                text2=true;
            }
            else if(text2){
                text2=false;
                text3=true;
            }
            else if(text3){
                text3=false;
                text4=true;
            }
        }
    }
}
void E_inttDefaultDisplay(){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glPointSize(5.0f);
	glLineWidth(5.0f);
	glColor3ub(0, 0, 0);
    gluOrtho2D(-25.0, 25.0, -20.0, 20.0);
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void E_display(){
    glClear(GL_COLOR_BUFFER_BIT);
    E_PrintFunction();
    glutSwapBuffers();
}



//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//---------------md--wahiduzzaman-shuvo----------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
GLubyte* imageData;
int imageWidth, imageHeight;
int scene=0;
float rectPositionX = 0.0;
static float rotationAngle = 0.0;
float rectSpeed = 0.01;
GLuint textureID;
void window(float , float ,  float , float , float ,float , float ,float ,float, float ,float ,float  );
void FilledRectangle(float , float ,  float , float, float ,float ,float);
void drawText(char* , float , float );
GLubyte* earthImageData;
int earthImageWidth, earthImageHeight;
GLuint earthTextureID;
bool isRotation=true;
bool morphing = false;
float morphTime = 4.0f;
float morphProgress = 0.0f;
bool isEarthRendered=true;

void applyDarkFilter() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(0.0, 0.0, 0.0, 0.5); // Dark with 50% opacity
    glBegin(GL_QUADS);
    glVertex2f(-25, -20);
    glVertex2f(25, -20);
    glVertex2f(25, 20);
    glVertex2f(-25, 20);
    glEnd();

    glDisable(GL_BLEND);
}

void FlyingCar() {
    static float carTranslationX = -25.0f;
      glPushMatrix();

    glTranslatef(carTranslationX, 10.0f, 0.0f);

    glColor3f(0.4f, 0.5f, 0.85f);
    glBegin(GL_POLYGON);
glVertex2f(0.8998690813896, 0.0646881088762);
glVertex2f(0.9027515490542, 0.1799868154604);
glVertex2f(0.8508671310913, 0.1857517507896);
glVertex2f(0.8335723251037, 0.2693433130631);
glVertex2f(0.5482080263078, 0.4192316316226);
glVertex2f(0.225371647872, 0.5806498208405);
glVertex2f(-0.1522316161913, 0.4682335819209);
glVertex2f(0.035128782008, 0.2693433130631);
glVertex2f(0.3579651604438, 0.07333551187);
glVertex2f(0.3694950311022, -0.1140248863293);
    glPopMatrix();
    glEnd();
        glColor3f(0.0f, 0.85f, 0.85f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1522316161913, 0.4682335819209);
glVertex2f(0.035128782008, 0.2693433130631);
glVertex2f(0.3579651604438, 0.07333551187);
glVertex2f(0.3694950311022, -0.1140248863293);
glVertex2f(0.1686393841418, -0.1554724607912);
glVertex2f(-0.3020029694221, 0.0193375562469);
glVertex2f(-0.2926631277112, 0.4899694207589);
      glEnd();
  glColor3f(0.0f, 0.85f, 0.85f);
    glBegin(GL_POLYGON);
glVertex2f(0.2196865410288, 0.5728751780023);
glVertex2f(-0.1568126869097, 0.6740242243141);
glVertex2f(-0.4883567831541, 0.5391588292317);
glVertex2f(-0.1315254253318, 0.4520582615742);
    glEnd();

    glColor3f(0.0f, 0.85f, 0.85f);
    glBegin(GL_POLYGON);
    glVertex2f(0.050690796927, 0.6250997643529);
glVertex2f(-0.1497445804919, 0.6793661110776);
glVertex2f(0.0344984192752, 0.7686430040764);
glVertex2f(0.5702856229633, 0.6545531475339);
glVertex2f(0.6517535909028, 0.6697099787785);
glVertex2f(0.5513395839076, 0.6242394850448);
glVertex2f(0.1572619715489, 0.7303373037567);
    glEnd();

    glColor3f(0.0f, 0.85f, 0.85f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2928152041605, 0.458886546995);
glVertex2f(-0.4947699725796, 0.552324644602);
glVertex2f(-0.551684498225, 0.4809179762771);
glVertex2f(-0.5700440226268, 0.4258394030719);
glVertex2f(-0.5902394994687, 0.363417020106);
glVertex2f(-0.5773878323875, 0.3230260664221);
glVertex2f(-0.5718799750669, 0.289978922499);
glVertex2f(-0.5902394994687, 0.2606036834562);
glVertex2f(-0.5810597372678, 0.0751724869987);
glVertex2f(-0.2964871090408, -0.0194768020913);
glVertex2f(-0.2964871090408, 0.112087012644);
glVertex2f(-0.3, 0.3);
    glEnd();
    glColor3f(0.0f, 0.88f, 0.88f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2339999432905, 0.5373624801147);
glVertex2f(-0.3001251852949, 0.6062429405359);
glVertex2f(-0.6, 0.6);
glVertex2f(-0.8814762712503, 0.2425541095117);
glVertex2f(-0.962937844824, 0.2091970151314);
glVertex2f(-0.8178976020503, 0.121071298003);
glVertex2f(-0.825241411811, 0.1724779663279);
glVertex2f(-0.4580509237762, 0.5543560738841);
    glEnd();

glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_POLYGON);
     glVertex2f(-0.5775000408175, 0.1822055354878);
glVertex2f(-0.7576171996973, 0.2471845105267);
glVertex2f(-0.7781368760254, 0.2369246723627);
glVertex2f(-0.7952366062988, 0.2221049061257);
glVertex2f(-0.8, 0.2);
glVertex2f(-0.7940966242806, 0.1787855894331);
glVertex2f(-0.6424790158564, 0.1252064345765);
glVertex2f(-0.6470389439293, 0.148006074941);
glVertex2f(-0.6276592496195, 0.1639658231962);
glVertex2f(-0.6014396632003, 0.1844854995242);
     glEnd();

     glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_POLYGON);
    glVertex2f(0.5668179872495, 0.650659402129);
glVertex2f(0.7523490353291, 0.540547479285);
glVertex2f(0.7496239687727, 0.5740402229216);
glVertex2f(0.7717622684243, 0.5866906798653);
glVertex2f(0.8, 0.6);
glVertex2f(0.8255267104352, 0.5761486324122);
glVertex2f(0.6191825939918, 0.6888146117854);
glVertex2f(0.6, 0.7);
glVertex2f(0.5778491771085, 0.6985401216403);
glVertex2f(0.5640713714807, 0.6880041526308);
glVertex2f(0.5511040250075, 0.6750368061576);
glVertex2f(0.5519144841621, 0.6596380822207);
     glEnd();


      glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_POLYGON);
    glVertex2f(0.5429451632702, 0.4264180995186);
glVertex2f(0.2361446618815, 0.5828261982658);
glVertex2f(0.0472518041637, 0.5455288824107);
glVertex2f(-0.1163751299102, 0.4625122761526);
glVertex2f(0.0472518041637, 0.2603848870024);
glVertex2f(0.2686294208521, 0.3602454423564);
      glEnd();
      glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_POLYGON);
      glVertex2f(-0.0020235560812, 0.1596649016911);
glVertex2f(0.0140965478321, 0.2624305641382);
glVertex2f(-0.1450894783115, 0.4377366941951);
glVertex2f(-0.2680052706503, 0.4538567981084);
glVertex2f(-0.2700202836394, 0.222130304355);
glEnd();

 glColor3f(0.0f, 0.88f, 0.88f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2339999432905, 0.5373624801147);
    glVertex2f(-0.3001251852949, 0.6062429405359);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.8814762712503, 0.2425541095117);
    glVertex2f(-0.962937844824, 0.2091970151314);
    glVertex2f(-0.8178976020503, 0.121071298003);
    glVertex2f(-0.825241411811, 0.1724779663279);
    glVertex2f(-0.4580509237762, 0.5543560738841);
    glEnd();

    // Headlights
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5775000408175, 0.1822055354878);
    glVertex2f(-0.6470389439293, 0.148006074941);
    glVertex2f(-0.6276592496195, 0.1639658231962);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.7940966242806, 0.1787855894331);
    glVertex2f(-0.6424790158564, 0.1252064345765);
    glVertex2f(-0.6470389439293, 0.148006074941);
    glVertex2f(-0.6276592496195, 0.1639658231962);
    glEnd();

    glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_POLYGON);
    glVertex2f(0.5519144841621, 0.6596380822207);
    glVertex2f(0.5511040250075, 0.6750368061576);
    glVertex2f(0.5640713714807, 0.6880041526308);
    glVertex2f(0.5778491771085, 0.6985401216403);
    glVertex2f(0.6, 0.7);
    glVertex2f(0.6191825939918, 0.6888146117854);
    glVertex2f(0.8255267104352, 0.5761486324122);
    glEnd();
glPopMatrix();

    carTranslationX += 0.1f; // Adjust the speed as needed

    if (carTranslationX > 25.0f) {
        carTranslationX = -25.0f;
    }
}


void DrawWheel(float x, float y, float radius) {
    const int numSegments = 50;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(x, y);
    for (int i = 0; i <= numSegments; ++i) {
        float theta = 2.0f * PI * float(i) / float(numSegments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}static float carTranslationX = -20.0f;
void car(){
    float carTranslationY=0;
    float scaleFactor=0;
    if(carTranslationX<-8){
         carTranslationY =-18-18*(carTranslationX+22)/(-23);

         scaleFactor = 4.0f - (carTranslationX + 80.0f) / 40.0f;
    }
    else {
         carTranslationY =-5.47+0.147*(carTranslationX+8);

     scaleFactor = 3.2f - (carTranslationX + 80.0f) / 40.0f;
    }
    glPushMatrix();

    glTranslatef(carTranslationX+4, carTranslationY, 0.0f);

    glScalef(scaleFactor, scaleFactor, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.20f, 1.0f);
    glVertex2f(0.1688717871834, 0.8483038868723);
    glVertex2f(0.7288208760308, 0.516905446534);
    glVertex2f(0.5231252923725, 0.4506257584664);
    glVertex2f(-0.0370713765878, 0.7699607569833);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.20f, 0.20f, 1.0f);
    glVertex2f(0.2337250189964, 0.5653858165625);
    glVertex2f(-0.1023153998919, 0.3704783293016);
    glVertex2f(-0.6621581704156, 0.690090060235);
    glVertex2f(-0.3216567838657, 0.8906307541539);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.20f, 0.20f, 0.8f);
        glVertex2f(0.512647845376, 0.4482373003565);
    glVertex2f(0.2309235937558, 0.5678372184971);
    glVertex2f(-0.3240569814495, 0.8893384865879);
    glVertex2f(-0.0379053215229, 0.7672592937402);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.20f, 0.20f, 0.8f);
    glVertex2f(-0.6648390720314, 0.6966889454467);
    glVertex2f(-0.1050480942046, 0.3639339369552);
    glVertex2f(-0.2800910934631, -0.0589422196694);
    glVertex2f(-0.2796719562143, -0.2290408973489);
    glVertex2f(-0.8398820712899, 0.0883711955482);
    glVertex2f(-0.8381489722873, 0.2599479968016);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.20f, 0.20f, 0.65f);
        glVertex2f(-0.2771432642224, -0.2336702699502);
    glVertex2f(0.7318081061215, 0.3357195658872);
    glVertex2f(0.7318081061215, 0.5211885677887);
    glVertex2f(0.5259375140109, 0.4470009670281);
    glVertex2f(0.2366058710447, 0.563846438226);
    glVertex2f(-0.106511782473, 0.3709586762485);
    glVertex2f(-0.2808526442604, -0.0648934782199);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.50f, 0.50f, 0.5f);
    glVertex2f(0.1113683831708, 0.2497420142034);
    glVertex2f(0.4388305578278, 0.4322847583739);
    glVertex2f(0.2200579560357, 0.5228594024279);
    glVertex2f(0.0653843331126, 0.4434324068728);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.50f, 0.50f, 0.5f);
    glVertex2f(0.0821058058611, 0.2302336293302);
    glVertex2f(-0.1868312141763, 0.0755600064071);
    glVertex2f(-0.0878958337481, 0.3514643067564);
    glVertex2f(0.0444824921771, 0.4294978462491);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.50f, 0.50f, 0.5f);
    glVertex2f(-0.1526518996102, 0.3557086931019);
    glVertex2f(-0.2864236815977, 0.0268530623826);
    glVertex2f(-0.7567547436857, 0.2901522400121);
    glVertex2f(-0.6215895056358, 0.6217947828562);
    glEnd();


    const float wheelRadius = 0.1f;
    const float wheelOffset = 0.2f;
    DrawWheel(0.5f, 0.2f, wheelRadius);
    DrawWheel(0.05f, -0.03f, wheelRadius);

    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.1f, 0.6f);
    glVertex2f(0.1f, 0.7f);
    glVertex2f(0.15f, 0.7f);
    glVertex2f(0.15f, 0.6f);
    glEnd();
    glPopMatrix();

    carTranslationX += 0.0f;

    if (carTranslationX > 5.0f) {
            carTranslationX=-25;
            isShuvo=false;
            isAbha = true;
            text1=true;
            text2=false;
            text3=false;
            text4=false;
    }
}
void morphEffect(int value) {
    if (morphing) {
        morphProgress += 1.0f / (morphTime * 60.0f);
        if (morphProgress >= 1.0f) {
            morphing = false;
            morphProgress = 0.0f;
        }

        glutPostRedisplay();
        glutTimerFunc(1000 / 60, morphEffect, 0);
    }
}



void ApplyTexture(float x1, float y1,float x2, float y2,float x3, float y3,float x4, float y4, GLuint texture )
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex2f(x1,y1);

    glTexCoord2f(1.0, 0.0);
    glVertex2f(x2,y2);

    glTexCoord2f(1.0, 1.0);
    glVertex2f(x3,y3);

    glTexCoord2f(0.0, 1.0);
    glVertex2f(x4,y4);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
void loadImage(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    fseek(file, 18, SEEK_SET);
    fread(&imageWidth, sizeof(int), 1, file);
    fread(&imageHeight, sizeof(int), 1, file);

    int imageSize = imageWidth * imageHeight * 3;

    imageData = new GLubyte[imageSize];

    fseek(file, 54, SEEK_SET);
    fread(imageData, sizeof(GLubyte), imageSize, file);
for (int i = 0; i < imageSize; i += 3) {
        GLubyte temp = imageData[i];
        imageData[i] = imageData[i + 2];
        imageData[i + 2] = temp;
    }
    fclose(file);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}
void drawCircle(double x, double y) {
    glBegin(GL_TRIANGLE_FAN);

    glColor3ub(255, 255, 255);
    glVertex2d(x, y);

    int numSegments = 100;
    for (int i = 0; i <= numSegments; ++i) {
        double angle = 2.0 * M_PI * i / numSegments;
        double dx = cos(angle);
        double dy = sin(angle);

        double gradientFactor = 0.5 * (1.0 + sin(angle));
        glColor3ub(255 * gradientFactor, 255 * gradientFactor, 255 * gradientFactor); // Ash color
        glVertex2d(x + dx, y + dy);
    }

    glEnd();
}
float randomFloat(float min, float max) {
    return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

void drawRandomDotsInRectangle(float left, float right, float bottom, float top, int numDots) {
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1);
    glBegin(GL_POINTS);

    for (int i = 0; i < numDots; i++) {
        float randomX = randomFloat(left, right);
        float randomY = randomFloat(bottom, top);
        glVertex2f(randomX, randomY);
    }

    glEnd();
}

void b2(){
    glBegin(GL_POLYGON);
	glColor3f(0.8078, 0.5961, 0.3882);
    glVertex2d(-8.2, 6.0);
    glVertex2d(-8.3, 6.0);
    glVertex2d(-8.3, -3.5);
    glVertex2d(-8.2, -3.5);
    glEnd();
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3f(0.20, 0.2, 0.2);
    glVertex2d(-8.2005826407351,5.6);
    glVertex2d(-5.0343393725865,5.6);
    glVertex2d(-5.1435201749364,-3.2347343559195);
    glVertex2d(-8.2468124678867,-3.2170990125553);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.7078, 0.5961, 0.6882);
    glVertex2d(-7.7054046980247, 6.1880586898299);
    glVertex2d(-6.8353110956889, 6.3634263926263);
    glVertex2d(-5.3311957986277, 6.0261808103256);
    glVertex2d(-5.3244508869817, 5.6012513766267);
    glVertex2d(-6.7880967141668, 5.5135675252285);
    glVertex2d(-7.7391292562548, 5.4596082320604);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6098, 0.4824, 0.4667);
    glVertex2d(-7.0790891718411, 6.1108595321534);
    glVertex2d(-6.8845201104512, 6.1007956151849);
    glVertex2d(-6.9014037146236, -3.2745103046623);
    glVertex2d(-7.1420562920646, -3.2745103046623);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.3098, 0.2824, 0.2667);
    glVertex2d(-5.15, 5.8);
    glVertex2d(-4.9, 5.8);
    glVertex2d(-4.9, -3.25);
    glVertex2d(-5.15, -3.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6098, 0.4824, 0.2667);
    glVertex2d(-5.85, 5.82);
    glVertex2d(-5.6, 5.822);
    glVertex2d(-5.6, -3.18);
    glVertex2d(-5.85, -3.18);
    glEnd();

    for(float i=-5.0;i<4;i+=0.8){
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3f(0.5,0.50,0.5);
    glVertex2d(-8.4459787140224, 1.7591604246912 + i * 1.0);
    glVertex2d(-8.4357507704536, 1.8767817757327 + i * 1.0);
    glVertex2d(-7.7760484102647, 1.94326340893 + i * 1.0);
    glVertex2d(-7.2544232882548, 1.9841751832053 + i * 1.0);
    glVertex2d(-6.8862173197773, 1.9944031267741 + i * 1.0);
    glVertex2d(-6.6305187305567, 1.9995170985585 + i * 1.0);
    glVertex2d(-6.3339083670609, 1.9074656064391 + i * 1.0);
    glVertex2d(-6.1088936085469, 1.8818957475171 + i * 1.0);
    glVertex2d(-5.8225111886199, 1.8614398603794 + i * 1.0);
    glVertex2d(-5.5412427404773, 1.8614398603794 + i * 1.0);
    glVertex2d(-5.3060000383945, 1.8614398603794 + i * 1.0);
    glVertex2d(-5.0093896748986, 1.8767817757327 + i * 1.0);
    glVertex2d(-4.9326800981325, 1.8767817757327 + i * 1.0);
    glVertex2d(-4.9275661263481, 1.8000721989665 + i * 1.0);
    glVertex2d(-5.2906581230412, 1.7745023400445 + i * 1.0);
    glVertex2d(-5.8429670757575, 1.7745023400445 + i * 1.0);
    glVertex2d(-6.2060590724507, 1.7898442553977 + i * 1.0);
    glVertex2d(-6.5180113512997, 1.8665538321638 + i * 1.0);
    glVertex2d(-6.6663165330476, 1.9023516346547 + i * 1.0);
    glVertex2d(-6.9373570376214, 1.9023516346547 + i * 1.0);
    glVertex2d(-7.2493093164704, 1.8921236910859 + i * 1.0);
    glVertex2d(-7.7811623820491, 1.8460979450262 + i * 1.0);
    glEnd();
    }
    window(-6.7573604202884,3.7534925115058,0.45, 0.75, 4, 0.0, 0.5647, 0.6314, 0.8, 0.9,0.9,0.9);
    window(-7.7573604202884,2.7534925115058,0.45, 0.75, 1, 0.0, 0.5647, 0.6314, 0.8, 0.9,0.9,0.9);
    window(-6.94202884,4.7534925115058,0.65, 0.75, 4, 0.0, 0.5647, 0.6314, 0.8, 0.9,0.9,0.9);
    window(-5.7573604202884,-1.7534925115058,0.85, 0.75, 9, 0.0, 0.5647, 0.6314, 0.8, 0.9,0.9,0.9);
    window(-6.7573604202884,1.7534925115058,0.45, 0.75, 1, 0.0, 0.5647, 0.6314, 0.8, 0.9,0.9,0.9);

}
void b3(){

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0); // Set color (use the converted values)
    glVertex2f(-4.9644059270232,6.1);
    glVertex2f(-4.1767686659812,6.1);
    glVertex2f(-4.1767686659812,-3.2246030375112);
    glVertex2f(-4.9644059270232,-3.2246030375112);
    glEnd();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(rectPositionX -4.9644059270232,6.1);
    glTexCoord2f(1.0, 0.0); glVertex2f(rectPositionX -4.1767686659812,6.1);
    glTexCoord2f(1.0, 1.0); glVertex2f(rectPositionX -4.1767686659812,-3.2246030375112);
    glTexCoord2f(0.0, 1.0); glVertex2f(rectPositionX -4.9644059270232,-3.2246030375112);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);

//----------------------------------------------------------------
        glBegin(GL_POLYGON);
            glColor3f(0.5, 0.5, 0.5);

        glVertex2d(-2.3, 10.5);

        glVertex2d(-0.8, 10.0);
        glVertex2d(-0.8, -4.7);
        glVertex2d(-2.3, -4.7);

        glEnd();

          glBegin(GL_POLYGON);
        glColor3f(0.3647, 0.4314, 0.4);
        glVertex2f(-2.2, 9.9);
        glVertex2f(-2.1, 9.9);
        glVertex2f(-2.1, -4.0);
        glVertex2f(-2.2, -4.0);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3f(0.3647, 0.4314, 0.4);
        glVertex2f(-1.8, 9.9);
        glVertex2f(-1.9, 9.9);
        glVertex2f(-1.9, -4.0);
        glVertex2f(-1.8, -4.0);
        glEnd();



            float iyy=0.5;
    for(float i=-1.8;i<7; i++){

                glBegin(GL_POLYGON);
        glColor3f(0.7647, 0.7314, 0.7); // Set color (use the converted values)
        glVertex2f(-5.3067625010728,6.8836838347392+i*iyy);
        glVertex2f(-5.3178046011334,6.4383191322937+i*iyy);
        glVertex2f(-4.2982506955352,7.1818205363762+i*iyy);
        glVertex2f(-4.2982506955352,7.6382273388822+i*iyy);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3f(0.3647, 0.4314, 0.8); // Set color (use the converted values)
        glVertex2f(-5.2535599436819,6.8408617393195+i*iyy);
        glVertex2f(-4.3582271496672,7.5292095634652+i*iyy);
        glVertex2f(-4.3639656174569,7.1965490422191+i*iyy);
        glVertex2f(-5.256037137791,6.5283123172802+i*iyy);
        glEnd();
    }

    float iy=-0.9;
    for(float i=0.0;i<15; i++){
        glBegin(GL_POLYGON);
        glColor3f(0.3647, 0.4314, 0.4); // Set color (use the converted values)
        glVertex2f(-2.3, 9.9+i*iy);
        glVertex2f(-1.7, 9.9+i*iy);
        glVertex2f(-1.7, 9.8+i*iy);
        glVertex2f(-2.3, 9.8+i*iy);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.3647, 0.4314, 0.4); // Set color (use the converted values)
        glVertex2f(-2.3, 9.43+i*iy);
        glVertex2f(-2.2, 9.43+i*iy);
        glVertex2f(-1.8, 8.9+i*iy);
        glVertex2f(-1.9, 8.9+i*iy);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.3647, 0.4314, 0.4); // Set color (use the converted values)
        glVertex2f(-2.3, 9.4+i*iy);
        glVertex2f(-1.7, 9.4+i*iy);
        glVertex2f(-1.7, 9.3+i*iy);
        glVertex2f(-2.3, 9.3+i*iy);
        glEnd();
            glBegin(GL_POLYGON);
        glColor3f(0.3647, 0.4314, 0.4); // Set color (use the converted values)
        glVertex2f(-1.8, 9.8+i*iy);
        glVertex2f(-2.2, 9.4+i*iy);
        glVertex2f(-2.1, 9.4+i*iy);
        glVertex2f(-1.7, 9.8+i*iy);
        glEnd();
    }

    for(int j=-5;j<2;j++){
        window(-4.3058669291909,8.4705040255692+j*2.15, 2.05, 2.15, 16.0, 1.0, 0.6784, 0.7569, 0.7961, 1.0, 1.0, 1.0 );
                window(-4.3058669291909,8.4705040255692+j*2.15, 0.5125, 0.5375, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 );
                window(-4.3058669291909+0.5125,8.4705040255692+j*2.15, 0.5125, 0.5375, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 );

    }
int k=0;
    for(int j=-5;j<3;j+=2, k++){
        window(-4.3058669291909+k*0.5125,8.4705040255692+j*0.5375, 0.5125, 0.5375, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 );
    }    k=0;
    for(int j=-8;j<0;j+=2, k++){
        window(-4.3058669291909+k*0.5125,8.4705040255692+j*0.5375, 0.5125, 0.5375, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 );
    }    k=0;
    for(int j=-12;j<-4;j+=2, k++){
        window(-4.3058669291909+k*0.5125,8.4705040255692+j*0.5375, 0.5125, 0.5375, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 );
    }    k=0;
    for(int j=-16;j<-8;j+=2, k++){
        window(-4.3058669291909+k*0.5125,8.4705040255692+j*0.5375, 0.5125, 0.5375, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 );
    }


}
void b4(){
    float ix=-0.4,jy=0.6;
    for(float i=4,j=4; i>-2;i-=1,j-=1){
            glColor3ub(215,136,71); // Ash color
        glBegin(GL_POLYGON);

        glVertex2d(-10.7117330590915 + i * ix, -5.7357881642875 + j * jy);
        glVertex2d(-10.3870756052924 + i * ix, -5.1654439886946+ j * jy);
        glVertex2d(-10.1326143577202 + i * ix, -4.7442667513336+ j * jy);
        glVertex2d(-9.9571238421531 + i * ix, -4.5775507615449+ j * jy);
        glVertex2d(-9.7289861719159 + i * ix, -4.4634819264263+ j * jy);
        glVertex2d(-9.4745249243437 + i * ix, -4.4371583490913+ j * jy);
        glVertex2d(-9.2288382025498 + i * ix, -4.4722564522047+ j * jy);
        glVertex2d(-8.9392788518642 + i * ix, -4.5863252873233+ j * jy);
        glVertex2d(-8.1407970060341 + i * ix, -4.902208215344+ j * jy);
        glVertex2d(-7.6406490366679 + i * ix, -5.1127968340244+ j * jy);
        glVertex2d(-10.9135471519936 + i * ix, -6.1481908758701+ j * jy);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2d(-7.6406490366679 + i * ix, -5.1127968340244+ j * jy);
        glVertex2d(-7.7378394089462 + i * ix, -4.9704389088859+ j * jy);
        glVertex2d(-7.3101531377664 + i * ix, -4.2983604827463+ j * jy);
        glVertex2d(-6.6648051035755 + i * ix, -4.5427526377061+ j * jy);
        glVertex2d(-6.5273345164106 + i * ix, -4.6496742055011+ j * jy);
        glVertex2d(-3.6900943424234 + i * ix, -5.6119683156555+ j * jy);
        glEnd();

        glColor3ub(117, 90, 59); // Ash color
        glBegin(GL_POLYGON);
        glVertex2d(-10.6272082406155 + i * ix, -5.785008936085+ j * jy);
        glVertex2d(-10.3526427659038 + i * ix, -5.3018793026983+ j * jy);
        glVertex2d(-10.1018377649653 + i * ix, -4.8266698272359+ j * jy);
        glVertex2d(-9.9275942906291 + i * ix, -4.631305931768+ j * jy);
        glVertex2d(-9.7111099740296 + i * ix, -4.5177836681853+ j * jy);
        glVertex2d(-9.5104659732788 + i * ix, -4.504583404978+ j * jy);
        glVertex2d(-9.2781413408305 + i * ix, -4.5309839313926+ j * jy);
        glVertex2d(-9 + i * ix, -4.6);
        glVertex2d(-8.185159547267 + i * ix, -4.9164316170454+ j * jy);
        glVertex2d(-7.7099500718045 + i * ix, -5.0959551966646+ j * jy);
        glVertex2d(-10.7644909779713 + i * ix, -6.0463741475894+ j * jy);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2d(-7.6406490366679 + i * ix, -5.1127968340244+ j * jy);
        glVertex2d(-7.2834227458177 + i * ix, -4.40146342312+ j * jy);
        glVertex2d(-6.657167848733 + i * ix, -4.6191251861311+ j * jy);
        glVertex2d(-6.611344319678 + i * ix, -4.70695377061+ j * jy);
        glVertex2d(-3.6328149311047 + i * ix, -5.7150712055011+ j * jy);
        glEnd();

        glColor3ub(200, 200, 200); // Ash color
        glBegin(GL_POLYGON);
        //glVertex2d(-3.6328149311047, -5.7150712560292);
        //glVertex2d(-3.6900943424234, -5.6119683156555);
        glVertex2d(-7.2882194993992 + i * ix, -4.534 + j * jy);
        glVertex2d(-7.2439009445849 + i * ix, -4.458682845 + j * jy);
        glVertex2d(-7.1685594014006 + i * ix, -4.46311417496836 + j * jy);
        glVertex2d(-7.1153771356235 + i * ix, -4.485273417496836 + j * jy);
        glVertex2d(-6.9691259047364 + i * ix, -4.662548348019 + j * jy);
        glVertex2d(-7.0799222917721 + i * ix, -4.680275608841255 + j * jy);
        glVertex2d(-7.1331045575492 + i * ix, -4.75118489883 + j * jy);
        glEnd();

        glBegin(GL_POLYGON);
        //glVertex2d(-3.6328149311047, -5.7150712560292);
        //glVertex2d(-3.6900943424234, -5.6119683156555);
        glVertex2d(-9.7186840268464 + i * ix, -4.6786 + j * jy);
        glVertex2d(-9.6328000021633 + i * ix, -4.638985 + j * jy);
        glVertex2d(-9.5589234596041 + i * ix, -4.6367416 + j * jy);
        glVertex2d(-9.4872856001528 + i * ix, -4.636736 + j * jy);
        glVertex2d(-9.361919346113 + i * ix, -4.78449019 + j * jy);
        glVertex2d(-9.4425119379957 + i * ix, -4.791210 + j * jy);
        glVertex2d(-9.5320592623099 + i * ix, -4.8091203 + j * jy);
        glVertex2d(-9.6148905373005 + i * ix, -4.838224 + j * jy);
        glEnd();
    }
}

void b5(){
    glColor3ub(163,81,21);
        glBegin(GL_POLYGON);

        glVertex2f(-24.9406285678565, -2.4721743052415);
    glVertex2f(-21.377682203161, -2.4457821099474);
    glVertex2f(-20.7442695161041, -1.7595850323024);
    glVertex2f(-14.858809965533, -1.6540162511263);
    glVertex2f(-13.1169250761263, -4.7155109052349);
    glVertex2f(-11.586177749072, -6.1934738417011);
    glVertex2f(-10.2137835937818, -7.3283382393448);
    glVertex2f(-13.4864158102429, -8.2520650746362);
    glVertex2f(-15.8089289961185, -8.3312416605183);
    glVertex2f(-17.6299904714073, -8.9910465428693);
    glVertex2f(-19.8205426808126, -8.3840260511064);
    glVertex2f(-21.6152119608074, -8.1992806840481);
    glVertex2f(-24.9934129584446, -8.1728884887541);
    glEnd();
        glColor3ub(142,142,142);
            glBegin(GL_POLYGON);

    glVertex2f(-24.9808214079402, -2.6706959585197);
    glVertex2f(-21.2730207540855, -2.5922832558702);
    glVertex2f(-20.6345173182253, -1.897770746689);
    glVertex2f(-14.9327936541405, -1.796954414711);
    glVertex2f(-13.1169250761263, -4.7155109052349);
    glVertex2f(-12.0146534795171, -6.271041376853);
    glVertex2f(-11.7164989926678, -7.357175578947);
    glVertex2f(-13.5693161609458, -7.7618138110997);
    glVertex2f(-15.8089289961185, -8.3312416605183);
    glVertex2f(-17.7647757258973, -7.6340333167357);
    glVertex2f(-19.894450631964, -7.101614590219);
    glVertex2f(-22.5352475154867, -7.229395084583);
    glVertex2f(-24.9934129584446, -8.1728884887541);
    glEnd();

        glColor3ub(72,72,72);
            glBegin(GL_POLYGON);
    glVertex2f(-23.6426784666414, -2.6080005384184);
    glVertex2f(-23.4084142269741, -3.4172770027238);
    glVertex2f(-21.68337755306, -3.5237607480271);
    glVertex2f(-22.066719036152, -2.7357810327824);

            glEnd();

                    glBegin(GL_POLYGON);
    glVertex2f(-20.8315075906333, -2.3737362987511);
    glVertex2f(-19.6175928941753, -2.4589232949938);
    glVertex2f(-19.2129546620226, -3.0339355196318);
    glVertex2f(-18.680535935506, -3.0339355196318);
    glVertex2f(-18.744426182688, -1.9052078194165);
    glVertex2f(-20.277792115056, -1.8839110703558);

            glEnd();

                    glBegin(GL_POLYGON);
                    glVertex2f(-22.8334020023361, -4.1839599689077);
    glVertex2f(-22.2796865267587, -4.1839599689077);
    glVertex2f(-21.619487305878, -4.3117404632717);
    glVertex2f(-20.8315075906333, -4.5673014519997);
    glVertex2f(-20.6398368490873, -5.4191714144264);
    glVertex2f(-20.8953978378154, -5.7599193993971);
    glVertex2f(-22.3861702720621, -5.6747324031544);


            glEnd();


                    glBegin(GL_POLYGON);
                    glVertex2f(-20.213901867874, -4.7376754444851);
    glVertex2f(-19.5537026469933, -4.1839599689077);
    glVertex2f(-18.105523710868, -4.3117404632717);
    glVertex2f(-18.3823814486566, -4.8015656916671);
    glVertex2f(-19.255548160144, -5.0784234294557);
    glVertex2f(-20.022231126328, -5.0997201785164);


            glEnd();


                    glBegin(GL_POLYGON);
    glVertex2f(-17.6156984824726, -4.1839599689077);
    glVertex2f(-15.2304625876779, -3.9283989801798);
    glVertex2f(-14.0165478912198, -5.3552811672444);
    glVertex2f(-14.7406373592825, -5.7386226503364);
    glVertex2f(-16.3591902878932, -5.5256551597297);

            glEnd();
                    glBegin(GL_POLYGON);
                    glVertex2f(-15.6563975688912, -1.7987240741131);
    glVertex2f(-15.4008365801632, -2.5867037893578);
    glVertex2f(-15.7415845651339, -3.1191225158744);
    glVertex2f(-18.0203367146253, -3.0978257668138);
    glVertex2f(-18.4675684448993, -2.2672525534478);

            glEnd();
                glColor3ub(62,62,62);
            glBegin(GL_POLYGON);

    glVertex2f(-19.2107546655302, -7.1071692568439);
    glVertex2f(-13.2271315419645, -5.4466422656152);
    glVertex2f(-14.400952346109, -6.2482759855187);
    glVertex2f(-18.8815122448556, -7.3648372382414);
    glVertex2f(-19.8262948433133, -8.4241389395425);

            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(-24.9653395834092, -6.4486844154945);
    glVertex2f(-21.2005240774337, -6.019237779832);
    glVertex2f(-20.7997072174819, -5.6041060320248);
    glVertex2f(-25, -6);


            glEnd();
            glBegin(GL_POLYGON);
    glVertex2f(-16.789026703182, -6.0995585247966);
    glVertex2f(-16.3895414607051, -6.0511360711631);
    glVertex2f(-17.6001028015441, -4.0900266990041);
    glVertex2f(-18.4232845133145, -2.5405081827303);
    glVertex2f(-18.7017136217075, -2.5284025693219);
    glVertex2f(-17.7332645490363, -4.8405747303242);

            glEnd();
            glBegin(GL_POLYGON);

    glVertex2f(-20.8807240352176, -4.1989772196796);
    glVertex2f(-20, -7);
    glVertex2f(-19.4885784932528, -6.8864233963419);
    glVertex2f(-20.7596679011337, -3.6784358431189);

            glEnd();
            glBegin(GL_POLYGON);

            glVertex2f(-16.35322462048, -4.1021323124125);
    glVertex2f(-15.421092388034, -3.0005214922491);
    glVertex2f(-14.9731846919236, -3.3152674408672);
    glVertex2f(-15, -4);
    glVertex2f(-15.8326832439192, -4.1868716062712);

            glEnd();
            glBegin(GL_POLYGON);
    glVertex2f(-24.2945070163833, -2.1047061000283);
    glVertex2f(-24, -2);
    glVertex2f(-23.3744803973457, -3.5089572554014);
    glVertex2f(-22.4665593917165, -5.4458554007436);
    glVertex2f(-22.7691997269263, -5.4942778543772);
    glVertex2f(-23.5802758252884, -3.932653724695);

            glEnd();
            glBegin(GL_POLYGON);


            glEnd();


}
void b6(){
    glColor3ub(222,241,250);
    glBegin(GL_POLYGON);
        glVertex2f(-22.6194280004367, 0.6519878708864);
    glVertex2f(-22.3063054681861, 0.8866723918644);
    glVertex2f(-22.2644848821426, 1.1794164941686);
    glVertex2f(-22.0553819519253, 1.2630576662555);
    glVertex2f(-21.7486976542733, 1.3327586429945);
    glVertex2f(-21.7068770682299, 1.6115625499509);
    glVertex2f(-21.2607908170997, 1.6115625499509);
    glVertex2f(-21.2607908170997, 1.2769978616033);
    glVertex2f(-21.1771496450128, 1.0539547360382);
    glVertex2f(-21.2239040961943, -2.9728367670065);
    glVertex2f(-22.6995428109654, -2.916081431823);
    glEnd();
     glColor3ub(126,126,126);
            glBegin(GL_POLYGON);

    glVertex2f(-24.9942233778807, 1.6079839826774);
    glVertex2f(-24.718866867889, 1.6355196336766);
    glVertex2f(-24.406796156565, 1.4886628283477);
    glVertex2f(-24.2048680492378, 1.5620912310121);
    glVertex2f(-23.9295115392461, 1.543734130346);
    glVertex2f(-23.5715480762569, 1.4886628283477);
    glVertex2f(-23.5715480762569, -3.0);
    glVertex2f(-25, -3);
            glEnd();

    window(-23.56801210261,-0.0468212795231, 2.15, 1.6, 25, 1, 0.6784, 0.8471, 0.90196, 0.4, 0.4, 0.4);
    window(-21.4148436772624,-0.0468212795231, 2.15, 1.6, 25, 1, 0.6784, 0.8471, 0.90196, 0.4, 0.4, 0.4);
    glColor3ub(126,126,126);
     glBegin(GL_POLYGON);

    glVertex2f(-16.1254193538266, 2.3450312730702);
    glVertex2f(-14.6526935272933, 2.3450312730702);
    glVertex2f(-14.6403176800115, 1.7386147562624);
    glVertex2f(-17.6971519586143, 1.8252456872349);
    glVertex2f(-19.145126090584, 1.8376215345167);
    glVertex2f(-19.4916498144742, 1.7881181453896);
    glVertex2f(-19.9495561639006, 1.7881181453896);
    glVertex2f(-20.1846972622546, 1.6891113671352);
    glVertex2f(-20.1875367423669, 1.9551360733656);
    glVertex2f(-20, 2);
    glVertex2f(-19.5, 2);
    glVertex2f(-19.3011124191531, 2.094165662521);
    glVertex2f(-16.0983601464496, 2.094165662521);

            glEnd();
            glBegin(GL_POLYGON);
    glVertex2f(-19.9, 1.9187428311338);
    glVertex2f(-19.5295458910456, 1.9187428311338);
    glVertex2f(-19.5295458910456, -1.698516428201);
    glVertex2f(-19.9, -1.698516428201);

            glEnd();

            glBegin(GL_POLYGON);
            glVertex2f(-20.12, 1.7001906140432);
    glVertex2f(-20.07, 1.7001906140432);
    glVertex2f(-20.07, -1.7286780843515);
    glVertex2f(-20.12, -1.7286780843515);
    glEnd();


            glColor3ub(100,100,100);
    for(float i=0; i<8;i++){
            glBegin(GL_POLYGON);
    glVertex2f(-20.2042168758298, 1.6813577702768-i*0.5);
    glVertex2f(-20.1097593625638, 1.7504730238861-i*0.5);
    glVertex2f(-19.932101834123, 1.7810947692931-i*0.5);
    glVertex2f(-19.7612125785131, 1.7873065583961-i*0.5);
    glVertex2f(-19.5666980645178, 1.7873065583961-i*0.5);
    glVertex2f(-19.5684366025461, 1.5884602159331-i*0.5);
    glVertex2f(-19.8384850418358, 1.5938611847189-i*0.5);
    glVertex2f(-20.0635254079107, 1.6046631222905-i*0.5);
    glVertex2f(-20.1769457524124, 1.6316679662194-i*0.5);

            glEnd();
    }
     glColor3ub(66,66,66);

            glBegin(GL_POLYGON);
    glVertex2f(-19.7, 2.2);
    glVertex2f(-19.3, 2.2);
    glVertex2f(-19.3, -1.7512534451493);
    glVertex2f(-19.7, -1.7248084759068);

            glEnd();

     glColor3ub(126,126,126);

            glBegin(GL_POLYGON);
    glVertex2f(-19.3249794033049, 2.3055517433204);
    glVertex2f(-19.0702749996826, 2.3090425720848);
    glVertex2f(-19.071336042802, -1.7512534451493);
    glVertex2f(-19.328997795409, -1.7248084759068);

            glEnd();
             glColor3ub(90,90,90);

            glBegin(GL_POLYGON);
    glVertex2f(-19.1394271127773, 1.83);
    glVertex2f(-12.9964819356408, 1.83);
    glVertex2f(-12.9964819356408, -1.7132198948771);
    glVertex2f(-19.1394271127773, -1.7132198948771);

            glEnd();
            window(-17.6640745864444,1.8668845246464, 4.65,1.85, 16, 5, 0.353, 0.353,0.353, 0.7,0.7,0.7);
                     glColor3ub(220, 180, 0);

            glBegin(GL_POLYGON);
    glVertex2f(-18.6045720182545, 1.5768279765598);
    glVertex2f(-18.6, 1.4);
    glVertex2f(-18.5546230672355, 1.3901140406079);
    glVertex2f(-18.5237022880333, 1.3615717828828);
    glVertex2f(-18.5177559843406, 1.316379874818);
    glVertex2f(-18.2299548856122, 1.3187583962951);
    glVertex2f(-18.2335226678278, 1.3805999546996);
    glVertex2f(-18.2573078825988, 1.4412522523654);
    glVertex2f(-18.2834716188468, 1.5007152892928);
    glVertex2f(-18.3298527876502, 1.5482857188347);
    glVertex2f(-18.4, 1.6);
    glVertex2f(-18.4761318584914, 1.6160735809318);
    glVertex2f(-18.6069505397316, 1.6362910134871);

            glEnd();
                    glBegin(GL_POLYGON);

            glVertex2f(-18.5177559843406, 1.316379874818);
    glVertex2f(-18.2299548856122, 1.3187583962951);
    glVertex2f(-18.2299548856122, -1.693960985201);
    glVertex2f(-18.5177559843406, -1.693960985201);


            glEnd();

            glBegin(GL_POLYGON);
    glVertex2f(-19.1045720182545, 1.5768279765598);
    glVertex2f(-19.1, 1.4);
    glVertex2f(-19.0546230672355, 1.3901140406079);
    glVertex2f(-19.0237022880333, 1.3615717828828);
    glVertex2f(-19.0177559843406, 1.316379874818);
    glVertex2f(-18.7299548856122, 1.3187583962951);
    glVertex2f(-18.7335226678278, 1.3805999546996);
    glVertex2f(-18.7573078825988, 1.4412522523654);
    glVertex2f(-18.7834716188468, 1.5007152892928);
    glVertex2f(-18.8298527876502, 1.5482857188347);
    glVertex2f(-18.9, 1.6);
    glVertex2f(-18.9761318584914, 1.6160735809318);
    glVertex2f(-19.1069505397316, 1.6362910134871);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-19.0177559843406, 1.316379874818);
    glVertex2f(-18.7299548856122, 1.3187583962951);
    glVertex2f(-18.7299548856122, -1.693960985201);
    glVertex2f(-19.0177559843406, -1.693960985201);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-17.7, 1.316379874818);
    glVertex2f(-17.9, 1.3187583962951);
    glVertex2f(-17.9, -1.693960985201);
    glVertex2f(-17.7, -1.693960985201);
    glEnd();

}

void b7()
{

for (int i = 0; i < 19; ++i) {
    glColor3ub(170, 170, 169); // Ash color
    glBegin(GL_POLYGON);
    glVertex2f(-13.1931407840664, 6.1159170970838 - i * 0.5);
    glVertex2f(-12.7970185469901, 6.6781110625983 - i * 0.5);
    glVertex2f(-12.7860282571716, 5.7535422105071 - i * 0.5);
    glVertex2f(-13.2138007915073, 5.2638616647549 - i * 0.5);
    glEnd();

    glColor3ub(222, 241, 250); // Ash color
    glBegin(GL_POLYGON);
    glVertex2f(-13.1376731801911, 6.0972384240874 - i * 0.5);
    glVertex2f(-12.8655109117388, 6.5064751197164 - i * 0.5);
    glVertex2f(-12.8575645681343, 5.7773980940084 - i * 0.5);
    glVertex2f(-13.1317134224877, 5.449611420325 - i * 0.5);
    glEnd();

    glColor3ub(100, 100, 100); // Ash color
    glBegin(GL_POLYGON);
        glVertex2f(-12.8014018248235, 6.6516343243173- i * 0.5);
        glVertex2f(-12.8014018248235, 5.7670308408031- i * 0.5);
        glVertex2f(-11.858085720722, 5.7670308408031- i * 0.5);
        glVertex2f(-11.858085720722, 6.6516343243173- i * 0.5);
    glEnd();

    glColor3ub(70, 70, 70); // Ash color
    glBegin(GL_POLYGON);
    glVertex2f(-12.7231183307072, 6.5616083060836- i * 0.5);
    glVertex2f(-12.7231183307072, 5.8883702566833- i * 0.5);
    glVertex2f(-11.8737424195453, 5.8883702566833- i * 0.5);
    glVertex2f(-11.8737424195453, 6.5616083060836- i * 0.5);

    glEnd();
}

}
void b8(){
    glColor3ub(140, 140, 140); // Ash color
    glBegin(GL_POLYGON);
    glVertex2f(0.1058348537678, -1.1);
glVertex2f(0.3897087968188, -0.9247510573581);
glVertex2f(0.3897087968188, -2.99);
glVertex2f(0.1058348537678, -2.99);
 glEnd();
    glColor3ub(140, 140, 140); // Ash color
    glBegin(GL_POLYGON);
glVertex2f(0.3897087968188, -0.9247510573581);
glVertex2f(0.9068690287567, -0.9247510573581);
glVertex2f(0.9068690287567, -2.99);
glVertex2f(0.3897087968188, -2.99);
 glEnd();

 glBegin(GL_POLYGON);
/*glVertex2f(0.3897087968188, -0.9247510573581);
glVertex2f(0.9068690287567, -0.9247510573581);
glVertex2f(0.9068690287567, -2.99);
glVertex2f(0.3897087968188, -2.99);*///------------------------------------------------------------------------------------------------

glVertex2f(0.9068690287567, -0.9247510573581);
glVertex2f(3.7505156770584, -0.9247510573581);
glVertex2f(3.7505156770584, -2.99);
glVertex2f(0.9068690287567, -2.99);


 glEnd();
       glColor3ub(80, 80, 80); // Ash color

 for(float i=1;i<5;i++){
    glBegin(GL_POLYGON);
glVertex2f(0.1461926468564, -0.9577341103446-i*0.4);
glVertex2f(0.2772383870382, -0.8489414203824-i*0.4);
glVertex2f(0.2797109481737, -1.0665268003069-i*0.4);
glVertex2f(0.1536103302629, -1.1555390011851-i*0.4);
 glEnd();

     glBegin(GL_POLYGON);
glVertex2f(0.4665333858994,-0.81443986-i*0.4);
glVertex2f(0.7394470143688,-0.81443986-i*0.4);
glVertex2f(0.7394470143688,-1.037486117-i*0.4);
glVertex2f(0.4665333858994,-1.037486117-i*0.4);
 glEnd();
     glBegin(GL_POLYGON);
glVertex2f(1.0,-0.81443986-i*0.4);
glVertex2f(3.6,-0.81443986-i*0.4);
glVertex2f(3.6,-1.037486117-i*0.4);
glVertex2f(1.0,-1.037486117-i*0.4);
 glEnd();
 }

}
void b9(float x, float y){
    glColor3ub(213, 228, 227);
     glBegin(GL_POLYGON);

    glVertex2f(9.3517008576377+x, 6.0265333850131+y);
    glVertex2f(10.2371303363647+x, 6.5212610582363+y);
    glColor3ub(128,128,128);

    glVertex2f(10.2371303363647+x, -4.3559022757932+y);
    glColor3ub(128,128,128);
    glVertex2f(9.3517008576377+x, -4.3559022757932+y);
    glEnd();

    glColor3ub(120, 120, 120);

    glBegin(GL_POLYGON);
    glVertex2f(10.2344386923185+x, 6.5209437169882+y);
    glVertex2f(10.7284794772078+x, 6.4958455753967+y);
    glVertex2f(10.7284794772078+x, -4.3559022757932+y);
    glVertex2f(10.2344386923185+x, -4.3559022757932+y);
    glEnd();
    for (float i=0.0;i<12;i++){
        glColor3ub(80, 80, 80);
        glBegin(GL_POLYGON);
        glVertex2f(9.4651462974341+x, 5.94090120053+y-i*0.8);
        glVertex2f(10.2371303363647+x, 6.3566479164408+y-i*0.8);
        glVertex2f(10.2371303363647+x, 5.7890081233285+y-i*0.8);
        glVertex2f(9.4534113882109+x, 5.3941282672504+y-i*0.8);
        glEnd();

        glColor3ub(110, 110, 100);
        glBegin(GL_POLYGON);
        glVertex2f(10.3259414518259+x, 5.7958273289405+y-i*0.8);
        glVertex2f(10.6418720324403+x, 5.7891054016934+y-i*0.8);
        glVertex2f(10.643004715425+x, 5.7157637684243+y-i*0.8);
        glVertex2f(10.3227748876085+x, 5.7157637684243+y-i*0.8);
        glEnd();
    }

    glColor3ub(100, 100, 100);
    glBegin(GL_POLYGON);
    glVertex2f(10.99+x, 6.75+y);
    glVertex2f(12.5778802572785+x, 6.75+y);
    glVertex2f(12.5778802572785+x, -4.3559022757932+y);
    glVertex2f(10.99+x, -4.3559022757932+y);
    glEnd();
    glColor3ub(213, 228, 227);

    glBegin(GL_POLYGON);
    glVertex2f(10.7284794772078+x, 6.5018688027111+y);
    glVertex2f(10.99+x, 6.75+y);
    glVertex2f(10.99+x, -4.3559022757932+y);
    glVertex2f(10.7284794772078+x, -4.3559022757932+y);
    glEnd();

    for (float i=0.0;i<12;i++){
        if(i==5||i==1||i==3||i==9||i==2||i==8){
            glColor3ub(120, 120, 130);
            glBegin(GL_POLYGON);
            glVertex2f(10.99+x, 6.5+y-i*0.9);
            glVertex2f(12.4845904397872+x, 6.5+y-i*0.9);
            glVertex2f(12.4798453230378+x, 5.8+y-i*0.9);
            glVertex2f(10.99+x, 5.8+y-i*0.9);
            glEnd();


            glColor3ub(50, 50, 50);
            glBegin(GL_POLYGON);
            glVertex2f(10.99+x, 6.4848336343741+y-i*0.9);
            glVertex2f(12.456119739291+x, 6.4848336343741+y-i*0.9);
            glVertex2f(12.4371392722936+x, 5.8632233402089+y-i*0.9);
            glVertex2f(10.99+x, 5.8632233402089+y-i*0.9);
            glEnd();
        }else{
            glColor3ub(150, 160, 180);
            glBegin(GL_POLYGON);
            glVertex2f(10.99+x, 6.5+y-i*0.9);
            glVertex2f(12.4845904397872+x, 6.5+y-i*0.9);
            glVertex2f(12.4798453230378+x, 5.8+y-i*0.9);
            glVertex2f(10.99+x, 5.8+y-i*0.9);
            glEnd();


            glColor3ub(120, 120, 130);
            glBegin(GL_POLYGON);
            glColor3ub(60, 60, 70);
            glVertex2f(10.99+x, 6.484833634374+y-i*0.9);
            glColor3ub(120, 130, 120);
            glVertex2f(12.456119739291+x, 6.4848336343741+y-i*0.9);
            glVertex2f(12.4371392722936+x, 5.8632233402089+y-i*0.9);
            glVertex2f(10.99+x, 5.8632233402089+y-i*0.9);
            glEnd();
        }
    }
}
void b10(){
    window(7.0,3.95,2.9, 0.35, 36, 1, 0.6784, 1.0, 0.9019, 0.0,0.0,0.0);
    window(7.0,3.6,2.9, 2.15, 25, 1, 1.0, 0.8471, 0.9019, 0.0,0.0,0.0);
    window(7.0,1.45,2.9, 0.15, 36, 1, 1.0, 0.8471, 0.9019, 0.0,0.0,0.0);

}
void b12()
{
    glColor3ub(220,231,230);
    glBegin(GL_POLYGON);
    glVertex2f(19.0460709473041, 1.863463382616);
    glVertex2f(20.7221633501814, 1.9222736423661);
    glVertex2f(20.8397838696815, -2.99);
    glVertex2f(19.0754760771791, -2.99);
    glEnd();
    ApplyTexture(19.0460709473041, 1.863463382616,20.7221633501814, 1.9222736423661,20.8397838696815, -2.99, 19.0754760771791, -2.99, textures[4].textureID);
    glBegin(GL_POLYGON);

    glVertex2f(20.8397838696815, -2.8119522675152);
    glVertex2f(20.8691889995566, 0.4814222784892);
    glVertex2f(21.4223560719611, 0.541144184439);
    glVertex2f(21.9778666463693, 0.5184702834427);
    glVertex2f(22.0572252998562, 0.3144051744765);
    glVertex2f(22.1819317553355, -2.7805823115117);
        glEnd();
        glBegin(GL_POLYGON);
    glVertex2f(12.9513174567648, 1.4670682024667);
    glVertex2f(15.0, 1.4670682024667);
    glVertex2f(15.0, -3.2165210731895);
    glVertex2f(12.9513174567648, -3.2165210731895);
        glEnd();
    window(12.9513174567648, 1.4670682024667,2.05, 4.67, 64, 1,0.5,0.5,0.5, 0.0,0.0,0.0);
    window(12.9513174567648, 1.4670682024667,1.025, 2.33, 16, 1,0.5,0.5,0.9, 0.0,0.0,0.0);
}
void b13(float x)
{
    float xii=0.35;
    for(float i=0;i<10;i++){
            glColor3ub(222,241,250); // Ash color
                    glBegin(GL_POLYGON);

            glVertex2f(14.5057165763831+x, 0.1583935910196-i*xii);
    glVertex2f(14.7151184139062+x, 0.1766024464564-i*xii);
    glVertex2f(14.7287750554838+x, -0.0737693157995-i*xii);
    glVertex2f(14.4966121486647+x, -0.0919781712363-i*xii);
            glEnd();
                glColor3ub(126,127,140); // Ash color
            glBegin(GL_POLYGON);
    glVertex2f(14.1360312888776+x, 0.1381817614847-i*xii);
    glVertex2f(14.5057165763831+x, 0.1492891633012-i*xii);
    glVertex2f(14.5050792664428+x, -0.1262108194575-i*xii);
    glVertex2f(14.13052311010+x, -0.1317189982271-i*xii);
            glEnd();
            glBegin(GL_POLYGON);

    glVertex2f(14.7515361247798+x, 0.2266767989076-i*xii);
    glVertex2f(14.9017591821333+x, 0.2175723711892-i*xii);
    glVertex2f(14.8972069682741+x, -0.0373516049259-i*xii);
    glVertex2f(14.7151184139062+x, -0.0510082465035-i*xii);
            glEnd();

            glBegin(GL_POLYGON);

    glVertex2f(15.0118322098881+x, 0.2500117944712-i*xii);
    glVertex2f(15.1892786893102+x, 0.2552308085719-i*xii);
    glVertex2f(15.1892786893102+x, -0.0265959528634-i*xii);
    glVertex2f(15.0093996398499+x, -0.0301177682072-i*xii);
            glEnd();
             glBegin(GL_POLYGON);

    glVertex2f(15.2105897062187+x, 0.2390066062863-i*xii);
    glVertex2f(15.4405212106403+x, 0.254683754315-i*xii);
    glVertex2f(15.4483597846547+x, 0.0038493858551-i*xii);
    glVertex2f(15.2+x, 0-i*xii);

            glEnd();


                        glColor3ub(80,80,100); // Ash color

            glBegin(GL_POLYGON);

    glVertex2f(13.9993434743614+x, 0.1456315124581-i*xii);
    glVertex2f(14.7247864343522+x, 0.1299744701562-i*xii);
    glVertex2f(14.7352244625535+x, 0.2656688367732-i*xii);
            glEnd();

            glBegin(GL_POLYGON);

    glVertex2f(14.8630795915816+x, 0.2964894823917-i*xii);
    glVertex2f(15.4379083526355+x, 0.304328056406-i*xii);
    glVertex2f(15.4379083526355+x, 0.2416194642911-i*xii);
    glVertex2f(14.8683053075912+x, 0.2311680322719-i*xii);
            glEnd();
            glBegin(GL_POLYGON);

    glVertex2f(15.4830691363925+x, 0.2985937872486-i*xii);
    glVertex2f(17.8773151438419+x, 0.2897283537237-i*xii);
    glVertex2f(17.8772532092195+x, -0.0666614481346-i*xii);
    glVertex2f(15.4825132596741+x, -0.0644324883011-i*xii);

            glEnd();
            glColor3ub(50,50,60); // Ash color

            glBegin(GL_POLYGON);

    glVertex2f(15.6045519492678+x, 0.2411439239449-i*xii);
    glVertex2f(17.7925119207292+x, 0.2334803163391-i*xii);
    glVertex2f(17.8+x, 0-i*xii);
    glVertex2f(15.6+x, 0-i*xii);
            glEnd();
    }
}
void b14()
{
        glBegin(GL_POLYGON);
    glColor3ub(69, 69, 69);
glVertex2f(19.9938343352506, -2.097448231011);
glVertex2f(19.1533266803176, -3.9101171780601);
glVertex2f(19.128378973723, -6.2158089524521);
glVertex2f(19.828400222207, -6.1983789857049);glVertex2f(20, -2.5);

    glEnd();
        glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(20.6764396141934, -2.2141929375995);
    glVertex2f(19.7160376089773, -4.4058795648875);
    glVertex2f(24.8381816367965, -6.2035551131125);
    glVertex2f(24.8874330216794, -3.4454775596714);
    glEnd();
    ApplyTexture(20.6764396141934, -2.2141929375995,19.7160376089773, -4.4058795648875,24.8381816367965, -6.2035551131125,24.8874330216794, -3.4454775596714, textures[1].textureID);
       glBegin(GL_POLYGON);
    glColor3ub(201,90,68);
    glVertex2f(19.7160376089773, -4.4058795648875);
    glVertex2f(24.8381816367965, -6.2035551131125);
    glVertex2f(19.6167960684384, -6.058263527708);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(201,90,68);
    glVertex2f(19.8205200910469, -1.8742364429509);
    glVertex2f(19.9938343352506, -2.097448231011);
    glVertex2f(19.1533266803176, -3.9101171780601);
    glVertex2f(18.8445648034023, -3.9166865796966);
    glEnd();
    glBegin(GL_POLYGON);

    glColor3ub(201,90,68);
    glVertex2f(19.1533266803176, -3.9101171780601);
    glVertex2f(18.8445648034023, -3.9166865796966);
    glVertex2f(18.7974594482608, -6.1460477482346);
    glVertex2f(19.128378973723, -6.2158089524521);
    glEnd();

    glBegin(GL_POLYGON);    glColor3ub(120, 129, 129);

    glVertex2f(19.3202407473786, -3.8457888244624);
    glColor3ub(60, 60, 60);

    glVertex2f(20, -2.5);
    glColor3ub(60, 60, 60);

    glVertex2f(20.55, -2.6318523012612);
    glColor3ub(120, 129, 129);

    glVertex2f(19.9, -4.0151753160718);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(23.6038660779352, 3.2455044867428);
    glVertex2f(25.5, 3.2160993568678);
    glVertex2f(24.9565020521871, -3.400054865016);
    glVertex2f(22.8981429609343, -2.7825471376402);
    glEnd();

    ApplyTexture(23.6038660779352, 3.2455044867428,25.5, 3.2160993568678,24.9565020521871, -3.400054865016, 22.8981429609343, -2.7825471376402, textures[2].textureID);

}
void b15(){
    glColor3ub(90,90,90); // Ash color
    glBegin(GL_POLYGON);

    glVertex2f(-25, -30.990);
    glVertex2f(-25, -20.2);
    glVertex2f(-21.9679307744056, -17.36);
    glVertex2f(-17.9679307744056, -13.6);
    glVertex2f(-12.7551753510897, -9.7);
    glVertex2f(-7.7906463765032, -6.95);
    glVertex2f(-4.2658308045468, -5.3);
    glVertex2f(-1.2658308045468, -4.4);
    glVertex2f(4.11720973137, -2.95);
    glVertex2f(4.11720973137, -4.2);
    glVertex2f(3.45, -6.7);
    glVertex2f(3.11720973137, -9.7);
    glVertex2f(3.45, -13.7);
    glVertex2f(4.117209731709, -18.95);
    glVertex2f(-4, -9.04);
    glVertex2f(-9.4231109443004, -9.1350323017278);
    glVertex2f(-15.6880964039823, -12.785989930544);
            glEnd();
    //ApplyTexture(-23.0, -20, -12,-7, 4.11,-2.95, 4.11, -20, textures[7].textureID);
    }
void b16(){
    glColor3ub(222,241,240);
    glBegin(GL_QUADS);
    glVertex2f(-8.9, -16.4);
    glVertex2f(-7.4191135072419, -18.4280898314608+5);
    glVertex2f(-7.1097808528456, -18.5697252639052+5);
    glVertex2f(-8.4, -16.4);
    glVertex2f(-7.186920994217, -17.9526041329341+0.1+5);
    glVertex2f(-6.888273500205, -18.1470568865589+0.1+5);
    glVertex2f(-6.2178635966692+0.1, -17.0383468029099+0.2+5);
    glVertex2f(-6.4834348455703+0.1, -16.7860541164539+0.2+5);
    glVertex2f(-5.9921280351033, -16.3611401182122+0.3+5);
    glVertex2f(-5.8062281608726, -16.560318554888+0.3+5);
    glVertex2f(-4.9298430394991, -15.7503262457398+0.4+5);
    glVertex2f(-5.1024643512848, -15.5113121217288+0.4+5);
    glVertex2f(-4.6377146657079, -15.1395123732674+0.5+5);
    glVertex2f(-4.4385362290321, -15.312133685053+0.5+5);
    glVertex2f(-3.4957582954334, -14.6614841252455+0.6+5);
    glVertex2f(-3.6816581696641, -14.4623056885697+0.6+5);
    glVertex2f(4.2276224364423, -10.4283643998865+5+2);
    glVertex2f(4.2251931047197, -10.5061030150086+0.0+5+2);
    glVertex2f(3.7905377161877, -10.7021359812355+0.0+5+2);
    glVertex2f(3.7533599263903, -10.6278517759718+0.0+5+2);
    glVertex2f(3.6816358754681, -10.6632424666928+0.0+5+2);
    glVertex2f(3.726535984543, -10.7374800600433+0.0+5+2);
    glVertex2f(3.5189419998118, -10.8506071191384+0.0+2+5);
    glVertex2f(3.4792892162114, -10.7514751601375+0.0+2+5);
    glVertex2f(3.4128124907638, -10.7771328436436+0.0+2+5);
    glVertex2f(3.4547977910465, -10.8844286110328+0.0+2+5);
    glVertex2f(3.2635314230919, -10.9602354032099+0.0+2+5);
    glVertex2f(3.2110497977385, -10.8471083441148+0.0+2+5);
    glVertex2f(-3.2618964842807, -14.2125299719857+0.7+5);
    glVertex2f(-3.1409322213909, -14.3939763663203+0.7+5);
    glVertex2f(-2.3546645126077, -13.9464085936283+0.8+5);
    glVertex2f(-2.4877252017864, -13.6802872152709+0.8+5);
    glVertex2f(-1.9312895924936, -13.4141658369135+0.9+5);
    glVertex2f(-1.8224217558929, -13.6077086575371+0.9+5);
    glVertex2f(-1.0966361785545, -13.196430163712+1.0+5);
    glVertex2f(-1.2296968677332, -13.0028873430885+1.0+5);
    glVertex2f(-0.7700326687522, -12.74886239102+1.1+5);
    glVertex2f(-0.6853576847294, -12.9182123590656+1.1+5);
    glVertex2f(0.1251028766318, -12.5190302915295+1.2+5);
    glVertex2f(0.0016523814762, -12.3330036223106+1.2+5);
    glVertex2f(0.2772372444253, -12.2068644840429+1.3+5);
    glVertex2f(0.3765640649238, -12.3508883737658+1.3+5);
    glVertex2f(0.914138198636, -12.0066900689662+1.4+5);
    glVertex2f(0.85190949812, -11.8822326679343+1.4+5);
    glVertex2f(1.2877732435877, -11.699142712410+1.5+5);
    glVertex2f(1.3648659288838, -11.8343889071736+1.5+5);
    glVertex2f(1.8416346672766, -11.6158699020769+1.6+5);
    glVertex2f(1.7661648868188, -11.4585145804861+1.6+5);
    glVertex2f(2.080019036473, -11.3178894405814+1.7+5);
    glVertex2f(2.1594804928718, -11.4668796713292+1.7+5);
    glVertex2f(2.6370095547364, -11.2322095516522+1.8+5);
    glVertex2f(2.5625294186645, -11.1061662444536+1.8+5);
    glVertex2f(2.7745154357722, -11.0360335919954+1.9+5);
    glVertex2f(2.8304887222791, -11.1519782569025+1.9+5);
    glVertex2f(3.2, -11+2+5);
    glVertex2f(3.1422405556085, -10.8657684775738+2+5);

    glEnd();

}
void drawWindow() {

    for (int i = 0; i < 8; ++i) {

    if(i==3||i==4||i==5||i==7){
        glColor3ub(222,241,250);
        glBegin(GL_QUADS);
        glVertex2d(-11.7984320338832, 7.3819499611418 - i * 1.0);
        glVertex2d(-11.3552756771157, 7.9566683613247 - i * 1.0);
        glVertex2d(-11.3552756771157, 8.6975703952953 - i * 1.0);
        glVertex2d(-11.7915077158087, 8.0813060866655 - i * 1.0);
        glEnd();
    }
    else{
        glColor3ub(29, 29, 29);
        glBegin(GL_QUADS);
        glVertex2d(-11.7984320338832, 7.3819499611418 - i * 1.0);
        glVertex2d(-11.3552756771157, 7.9566683613247 - i * 1.0);
        glVertex2d(-11.3552756771157, 8.6975703952953 - i * 1.0);
        glVertex2d(-11.7915077158087, 8.0813060866655 - i * 1.0);
        glEnd();
    }
    }
}
void FilledRectangle(float x, float y,  float width, float height, float r=1.0f,float g=1.0f,float b=1.0f){
    glBegin(GL_POLYGON);
	glColor3f(r, g, b);
	glVertex2f(x, y);
	glVertex2f(x+width, y);
	glVertex2f(x+width, y-height);
	glVertex2f(x, y-height);
	glEnd();
}

void VoidRectangle(float x, float y,  float width, float height, float lineWidth, float r=0.0f,float g=0.0f,float b=0.0f){
    glLineWidth(lineWidth);
    glBegin(GL_LINES);
	glColor3f(r, g, b);
	glVertex2f(x, y);
	glVertex2f(x+width, y);

    glVertex2f(x+width, y);
	glVertex2f(x+width, y-height);

	glVertex2f(x+width, y-height);
	glVertex2f(x, y-height);

	glVertex2f(x, y-height);
    glVertex2f(x, y);

	glEnd();
}

void window(float x, float y,  float width, float height, float cell,float lineWidth, float r=1.0f,float g=1.0f,float b=1.0f, float rr=0.0f,float gg=0.0f,float bb=0.0f ){
    VoidRectangle(x,y,width,height, lineWidth);
    FilledRectangle(x,y,width,height, r,g,b);

    float n=sqrt(cell);
    float xd=width/n;
    float yd=height/n;

    for(int i=1;i<n;i++){
        glLineWidth(lineWidth);
        glBegin(GL_LINES);
        glColor3f(rr,gg,bb);
        glVertex2f(x+xd*i, y);
        glVertex2f(x+xd*i, y-height);

        glVertex2f(x, y-yd*i);
        glVertex2f(x+width, y-yd*i);
        glEnd();
    }
}
void drawRectangle() {
    drawCircle(-10.1,9);
    glBegin(GL_POLYGON);
    glColor3ub(180, 180, 180);
    glVertex2d(-11.9,8.1436566510149);
    glVertex2d(-11.2, 8.9776775565155);
    glVertex2d(-11.2, -3.0080803591956);
    glVertex2d(-11.9, -0.7839190964864);
    glEnd();
    drawWindow();
    glBegin(GL_POLYGON);
    glColor3ub(169, 169, 169);
    glVertex2d(-11.2, 8.9735773445842);
    glVertex2d(-10.6, 8.9572796898096);
    glVertex2d(-10.6, -3.2985567006883);
    glVertex2d(-11.2, -3.3148543554629);
    glEnd();
    for(int i =0;i<9;i++){
            if (i==2||i==5||i==6) window(-11.1,8.7-i*1.0,0.4,0.68,9, 2, 0.2,0.2,0.2);
            else window(-11.1,8.7-i*1.0,0.4,0.68,9, 2, 0.8706, 0.9451, 0.9804);
    }
    glBegin(GL_POLYGON);
    glColor3ub(200,200,200);

    glVertex2d(-10.6, 9.1);
    glVertex2d(-9.4310688980619, 9.0);
    glVertex2d(-8.6321977283327, 8.3619462247139);
    glVertex2d(-8.365907338423, 8.3952325234526);
    glVertex2d(-8.0996169485133, 8.228801029759);
    glVertex2d(-7.8333265586036, 8.2121578803897);
    glVertex2d(-7.8000402598649, 5.61582657877);
    glVertex2d(-7.80, -3.288258333836);
    glVertex2d(-10.6, -3.3381877819441);
    glEnd();
    for(int i =0;i<9;i++){
            if (i==2||i==5||i==6) {
                FilledRectangle(-10.4296578602233,8.0124400879574-i*1.1, 2.5, 0.9, 0.8706, 0.9451, 0.9804);
                VoidRectangle(-10.4296578602233,8.0124400879574-i*1.1, 2.5, 0.9, 0.2,0.2, 0.2);
                window(-10.4296578602233,8.0124400879574-i*1.1, 2.5,0.9,4, 2, 0.8706, 0.9451, 0.9804, 1.0,1.0,1.0);

            }
            else
            {
                FilledRectangle(-10.4296578602233,8.0124400879574-i*1.1, 2.5, 0.9, 0.8706, 0.9451, 0.9804);
                VoidRectangle(-10.4296578602233,8.0124400879574-i*1.1, 2.5, 0.9, 0.2,0.2, 0.2);
                window(-10.4296578602233,8.0124400879574-i*1.1, 2.5,0.9,4, 2, 0.2, 0.2, 0.3, 0.6,0.6,0.5);
            }
    }
    b2();
    b3();
    b7();
    b4();
    b6();
    b5();
    b8();
    b15();
    b16();
    car();
    b9(-0.0, -1.0);
    b10();
    b9(-5.2, -1.0);
    b12();
    b13(-0.0);
    b14();
    FlyingCar();
    if(text1) {
        I_AnimatedTextAdder("In the year 2223, Earth stood on the edge of ruin.                                                                  ", -10.0, 14.0);
    }
    glutTimerFunc(4000,I_Timer,0);
    if(text2){
            I_AnimatedTextAdder("Rampant destruction from neglect and misuse pushed humanity to the brink.                                             ", -10.0, 14.0);
    }
    glutTimerFunc(4000,I_Timer,0);
    if(text3){
            I_AnimatedTextAdder("The Hopebringer, a colossal spaceship, became our lifeline                                                            ", -10.0, 14.0);
    }
    if(text4){
            I_AnimatedTextAdder("Get to the space station,                                                                                            ", -6.0, 15.0);
            I_AnimatedTextAdder("press w/s to drive the car                                                                                    ", -6.0, 14.0);
            I_AnimatedTextAdder("press m to change the environment                                                                               ", -6.0, 13.0);
    }
    glutTimerFunc(2000,I_Timer,0);
}
bool isBlack = false;
void drawBackground() {
if(!isBlack){
    glBegin(GL_POLYGON);
    glColor3ub(173, 216, 230);
    glVertex2d(25.0, -10.0);
    glColor3ub(173, 216, 230);
    glVertex2d(-25.0, -10.0);

    glColor3ub(173, 216, 230);
    glVertex2d(-25.0, 20.0);


    glColor3ub(255, 182, 193);
    glVertex2d(-10.0, 20.0);

    glColor3ub(255, 182, 193);
    glVertex2d(25.0, 20.0);

     glColor3ub(255, 182, 193);
    glVertex2d(25.0, -9.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2d(-25.0, -3.0);
    glVertex2d(25.0, -3.0);
    glVertex2d(25.0, -20.0);
    glVertex2d(-25.0, -20.0);
    glEnd();
    ApplyTexture(-25.0, -3.0,25.0, -3.0,25.0, -20.0,-25.0, -20.0,textures[6].textureID );
    drawRectangle();//
                glColor3ub(255,255,255);

}else{
    glBegin(GL_POLYGON);
    glColor3ub(10,16,32);
    glVertex2d(25.0, -10.0);
    glColor3ub(10,16,32);
    glVertex2d(-25.0, -10.0);

    glColor3ub(137,46,86);
    glVertex2d(-25.0, 20.0);


    glColor3ub(81,41,100);
    glVertex2d(-10.0, 20.0);

    glColor3ub(81,41,100);
    glVertex2d(25.0, 20.0);

     glColor3ub(81,41,100);
    glVertex2d(25.0, -9.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2d(-25.0, -3.0);
    glVertex2d(25.0, -3.0);
    glVertex2d(25.0, -20.0);
    glVertex2d(-25.0, -20.0);
    glEnd();
    drawRandomDotsInRectangle(-25,25,-20,20, 1000);
    ApplyTexture(-25.0, -3.0,25.0, -3.0,25.0, -20.0,-25.0, -20.0,textures[6].textureID );
    drawRectangle();
    applyDarkFilter();

}
}


void loadBMP(const char* filename, GLubyte*& imageData, int& imageWidth, int& imageHeight) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    fseek(file, 18, SEEK_SET);
    fread(&imageWidth, sizeof(int), 1, file);
    fread(&imageHeight, sizeof(int), 1, file);

    int imageSize = imageWidth * imageHeight * 3;

    imageData = new GLubyte[imageSize];

    fseek(file, 54, SEEK_SET);
    fread(imageData, sizeof(GLubyte), imageSize, file);

    for (int i = 0; i < imageSize; i += 3) {
        GLubyte temp = imageData[i];
        imageData[i] = imageData[i + 2];
        imageData[i + 2] = temp;
    }
    fclose(file);
}

void sinit() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    loadBMP((path+"a1.bmp").c_str(), earthImageData, earthImageWidth, earthImageHeight);

    glGenTextures(1, &earthTextureID);
    glBindTexture(GL_TEXTURE_2D, earthTextureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, earthImageWidth, earthImageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, earthImageData);
}
bool isPointInsideSphere(float x, float y, float z, float sphereRadius) {
    float distance = sqrt(x * x + y * y + z * z);
    return distance <= sphereRadius;
}

void renderBitmapString(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(font, *string);
        ++string;
    }
}


void mouseClick(int button, int state, int x, int y) {
    if(isAbha){
        E_mouse(button, state, x, y);
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);

        GLdouble modelview[16];
        GLdouble projection[16];
        GLfloat winX, winY, winZ;
        GLdouble posX, posY, posZ;

        glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
        glGetDoublev(GL_PROJECTION_MATRIX, projection);

        winX = static_cast<GLfloat>(x);
        winY = static_cast<GLfloat>(viewport[3] - y);
        glReadPixels(x, static_cast<int>(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

        gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

        float sphereRadius = 2.0;
        float sphereCenterX = 0.0;
        float sphereCenterY = 0.0;
        float sphereCenterZ = 0.0;

        if (isPointInsideSphere(posX - sphereCenterX, posY - sphereCenterY, posZ - sphereCenterZ, sphereRadius)) {
            std::cout << "On the right track" << std::endl;
            isRotation=false;
        }
    }
}

void drawEarth() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, earthTextureID);

    GLUquadric* quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    gluSphere(quadric, 2.0, 100, 100);
    gluDeleteQuadric(quadric);
    glDisable(GL_TEXTURE_2D);

}

char* fullText = "";
char partialText[200] = "";
int currentCharIndex = 0;
float charDisplayTime = 100;

void drawText(char* a, float x, float y) {
    fullText=a;
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(x, y);

    int length = strlen(partialText);
    for (int i = 0; i < length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, partialText[i]);
    }
}

void updateText(int value) {
    if (currentCharIndex < strlen(fullText)) {
        partialText[currentCharIndex] = fullText[currentCharIndex];
        currentCharIndex++;
        glutPostRedisplay();
        glutTimerFunc(charDisplayTime, updateText, 0);
        return;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateText, 0);
}
static float translationy = -12.0;

void canvas1(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawStaticStars(1000);
    glLoadIdentity();
    gluLookAt(0.0, 10.0, 0.0,
                  0.0, 0.0, 0.0,
                  0.0, 0.0, -1.0);
    static float translationX = -12.0;
    if(isRotation){
        glTranslatef(translationX, 0.0, 0.0);
        glRotatef(-rotationAngle, 0.0, 0.0, 0.6);
      }
    else
      {
          glTranslatef(0.0, translationy, 0.0);
      }
glPushMatrix();
    translationX += 0.005;
    if(!isRotation) translationy += 0.05;

    if (translationX > 12.0) {
        translationX = -12.0;
    }
    rotationAngle += 0.1;
    if (rotationAngle > 360.0) {
        rotationAngle -= 360.0;
    }

    if (isEarthRendered) {
             glPushMatrix();
            drawEarth();
    glPopMatrix();
    }
    glPopMatrix();
}
    bool a=false;
    bool is3DView = true;

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (is3DView) {
        double aspectRatio = static_cast<double>(w) / static_cast<double>(h);
        gluPerspective(90.0, aspectRatio, 1.0, 100.0);
    } else {
        glOrtho(-25.0, 25.0, -20.0, 20.0, 1.0,1.0);
    }

    glMatrixMode(GL_MODELVIEW);
}

void reshape1(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double aspectRatio = static_cast<double>(w) / static_cast<double>(h);
    gluOrtho2D(-25.0 * aspectRatio, 25.0 * aspectRatio, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

bool ff=true;
void display(){
    if(AkashScene){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
        glOrtho(-25.0, 25.0, -20.0, 20.0, 0.0,0.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glDisable(GL_DEPTH_TEST);
            glutDisplayFunc(A_Display);
    glutTimerFunc(20, display, 0);
    }
    if(isSajin){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-25.0, 25.0, -20.0, 20.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glDisable(GL_DEPTH_TEST);
        IDisplay();
    }
   else if(isAbha){
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
        glOrtho(-25.0, 25.0, -20.0, 20.0, 0.0,0.0);
        E_inttDefaultDisplay();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glDisable(GL_DEPTH_TEST);
        E_PrintFunction();
    }
    else{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if(translationy>2){
            morphEffect(20);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-25.0, 25.0, -20.0, 20.0, -1.0, 1.0);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glDisable(GL_DEPTH_TEST);
            drawBackground();
            fullText="";


        }
        else{
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        double aspectRatio = static_cast<double>(1920) / static_cast<double>(1080);
        gluPerspective(90.0, aspectRatio, 1.0, 100.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glClearColor(0.0,0.0,0.0,1.0);
        glEnable(GL_DEPTH_TEST);
        if(ff){sinit(); ff=false;}
            canvas1();
        }
    }
        glutSwapBuffers();
}

void skeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':{
            carTranslationX += 0.35f;
            break;}
        case 'd': {
            if(text1){
                text1=false;
                text2=true;
            }
            else if(text2){
                text2=false;
                text3=true;
            }
            else if(text3){
                text3=false;
                text4=true;
            }
                break;}
        case 'a': {
            if(text2){
                text2=false;
                text1=true;
            }
            else if(text3){
                text3=false;
                text2=true;
            }
            else if(text4){
                text3=true;
                text4=false;
            }
                break;}
        case 's':
            carTranslationX -= 0.35f;
            break;
        case 'm':
            isBlack = !isBlack;
            break;
        default:
            break;
    }

    if(isAbha){
        if(canRocketControl)
        {
            if(key=='w' || key=='W')
            {
                RocketPositionY+=RocketMoveSpeed*5;
                FTPositionY+=FTMoveSpeed*5;
                SCPositionY+=SCMoveSpeed*5;
            }
            if(key=='s' || key=='S')
            {
                RocketPositionY-=RocketMoveSpeed*5;
                FTPositionY-=FTMoveSpeed*5;
                SCPositionY-=SCMoveSpeed*5;
            }
            if(key=='q' || key=='Q'){
               BigMeteorMoveSpeed = 1;
               SmallMeteorMoveSpeed = 0.55;
               StarsMoveSpeed=0.5;
            }
            if(key=='a' || key=='A'){
               BigMeteorMoveSpeed = 0.085;
               SmallMeteorMoveSpeed = 0.35;
               StarsMoveSpeed=0.05;
            }
            if(key=='i' || key=='I'){
              isSajin=true;
              isAbha = false;
              enteringScene=true;
              text1=true;
              text2=false;
              text3=false;
              text4=false;
            }
        }
    }
    if(isSajin) Ikeyboard(key, x, y);
    glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
    glutInitWindowSize(1920, 1080);
	glutCreateWindow("Rocket journey");

    if (PlaySoundA((path+"intersteller.wav").c_str(), NULL, SND_ASYNC | SND_FILENAME) == 0) {
        std::cerr << "Error playing WAV file" << std::endl;
        return 1;
    }

    loadImageAndStore((path+"image22.bmp").c_str());
    loadImageAndStore((path+"img2.bmp").c_str());
    loadImageAndStore((path+"img33.bmp").c_str());
    loadImageAndStore((path+"img4.bmp").c_str());
    loadImageAndStore((path+"img55.bmp").c_str());
    loadImageAndStore((path+"img6.bmp").c_str());
    loadImageAndStore((path+"ggg.bmp").c_str());
    loadImageAndStore((path+"aaaa.bmp").c_str());
    loadImageAndStore((path+"sk.bmp").c_str());


	glutDisplayFunc(display);
    E_inttDefaultDisplay();
    E_UpdateFunctions();
    glutKeyboardFunc(skeyboard);
    glutMouseFunc(mouseClick);


	glutMainLoop();
	return 0;

}
