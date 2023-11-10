#include "ros/ros.h" // ROS 기본 헤더파일
#include "ros_tutorials_topic/MsgTutorial.h"// MsgTutorial 메시지 파일 헤더(빌드 후 자동 생성됨)
int main(int argc, char **argv) // 노드 메인 함수
{
ros::init(argc, argv, "topic_publisher"); // 노드명 초기화
ros::NodeHandle nh; // ROS 시스템과 통신을 위한 노드 핸들 선언
// 퍼블리셔 선언, ros_tutorials_topic 패키지의 MsgTutorial 메시지 파일을 이용한
// 퍼블리셔 ros_tutorial_pub 를 작성한다. 토픽명은 "ros_tutorial_msg" 이며,
// 퍼블리셔 큐(queue) 사이즈를 100개로 설정한다는 것이다
ros::Publisher ros_tutorial_pub = nh.advertise<ros_tutorials_topic::MsgTutorial>("ros_tutorial_msg", 100);
// MsgTutorial 메시지 파일 형식으로 msg 라는 메시지를 선언
ros_tutorials_topic::MsgTutorial msg;
// 메시지에 사용될 변수 선언
int input1, input2;
std::string my_msg;
while (ros::ok())
{
//ROS_INFO("send msg = %d", msg.stamp.sec); // stamp.sec 메시지를 표시한다
std::cout << "Enter Input: ";
std::cin >> input1 >> input2;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' '); // 개행 문자 제거
std::getline(std::cin, my_msg); // 한 줄을 읽어 user_msg에 저장

msg.stamp = ros::Time::now(); // 현재 시간을 msg의 하위 stamp 메시지에 담는다
msg.data1 = input1;
msg.data2 = input2;
msg.message = my_msg;

ros_tutorial_pub.publish(msg); // 메시지를 발행한다
ros::spinOnce();
}
return 0;
}
