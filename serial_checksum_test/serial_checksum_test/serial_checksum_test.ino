#define NO_PACKET_LEN 13
char buff[NO_PACKET_LEN] = {0,};
char send_command_buff[NO_PACKET_LEN+1] = {0,};
int cnt_rcv = 0;

union
{
  int data;
  char bytedata[2];
} m_int_test, checksum;



union
{
  float data;
  char bytedata[4];
} m_float_test;


int check = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
    send_command_1();
  delay(1000);
  send_command_2();
  delay(1000);
  send_command_3();
  delay(1000);
  send_command_4();
  delay(1000);
  send_command_5();
  delay(3000000);
}

void send_command_1()
{
  send_command_buff[0] = '#';
  send_command_buff[1] = 'I';
  send_command_buff[2] = 0;
  send_command_buff[3] = 2;
  send_command_buff[4] = 0;
  send_command_buff[5] = 0;
  send_command_buff[6] = 0;
  send_command_buff[7] = 75;
  send_command_buff[8] = '*';
  
  for(int i = 0; i<13; i++){
    Serial.print(send_command_buff[i]);
    send_command_buff[i]=0;
  }
}


void send_command_2()
{
  send_command_buff[0] = '#';
  send_command_buff[1] = '*';
  send_command_buff[2] = '#';
  send_command_buff[3] = 'I';
  send_command_buff[4] = 0;
  send_command_buff[5] = 2;
  send_command_buff[6] = 0;
  send_command_buff[7] = 0;
  send_command_buff[8] = 0;
  send_command_buff[9] = 'K';
  send_command_buff[10] = '*';
  
  for(int i = 0; i<13; i++){
    Serial.print(send_command_buff[i]);
    send_command_buff[i]=0;
  }
}

void send_command_3()
{
  send_command_buff[0] = '#';
  send_command_buff[1] = '*';
  send_command_buff[2] = '#';
  send_command_buff[3] = 'I';
  send_command_buff[4] = 0;
  send_command_buff[5] = 2;
  send_command_buff[6] = 0;
  send_command_buff[7] = 0;
  send_command_buff[8] = 0;
  send_command_buff[9] = 'N';
  send_command_buff[10] = '*';
  
  for(int i = 0; i<13; i++){
    Serial.print(send_command_buff[i]);
    send_command_buff[i]=0;
  }
}

void send_command_4()
{
  send_command_buff[0] = '#';
  send_command_buff[1] = '*';
  send_command_buff[2] = '#';
  send_command_buff[3] = 'I';
  send_command_buff[4] = 0;
  send_command_buff[5] = 5;
  send_command_buff[6] = 0;
  send_command_buff[7] = 0;
  send_command_buff[8] = 0;
  send_command_buff[9] = 'N';
  send_command_buff[10] = '*';
  send_command_buff[11] = '*';
  
  for(int i = 0; i<13; i++){
    Serial.print(send_command_buff[i]);
    send_command_buff[i]=0;
  }
}

void send_command_5()
{
  send_command_buff[0] = '#';
  send_command_buff[1] = '*';
  send_command_buff[2] = '*';
  send_command_buff[3] = '*';
  send_command_buff[4] = '#';
  send_command_buff[5] = 'I';
  send_command_buff[6] = 0;
  send_command_buff[7] = 5;
  send_command_buff[8] = 0;
  send_command_buff[9] = 0;
  send_command_buff[10] = 0;
  send_command_buff[11] = 'M';
  send_command_buff[12] = '*';
  send_command_buff[13] = '*';
  
  for(int i = 0; i<13; i++){
    Serial.print(send_command_buff[i]);
    send_command_buff[i]=0;
  }
}
