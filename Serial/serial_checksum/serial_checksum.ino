#define NO_PACKET_LEN 9
char buff[NO_PACKET_LEN] = {0,};
char send_command_buff[NO_PACKET_LEN] = {0,};
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



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  delay(2000);
  m_int_test.data = 0;
  m_float_test.data = 0.0;
//  send_command();
}

void loop() {


}

void send_command(void)
{
  int i, check_sum = 0;
  
  send_command_buff[0] = '#';
  send_command_buff[1] = 'F'; 

//  send_command_buff[1] = 'I'; 
  
  if(send_command_buff[1] == 'I')
  {
    send_command_buff[2] = m_int_test.bytedata[1];
    send_command_buff[3] = m_int_test.bytedata[0];
  }
  
  if(send_command_buff[1] == 'F')
  {
    send_command_buff[2] = m_float_test.bytedata[3];
    send_command_buff[3] = m_float_test.bytedata[2];
    send_command_buff[4] = m_float_test.bytedata[1];
    send_command_buff[5] = m_float_test.bytedata[0];
  }
  
  for(i = 1; i < 6; i++)
  {
    check_sum += send_command_buff[i];
  }
  
  checksum.data = check_sum;
  
  send_command_buff[6] = checksum.bytedata[1]; //checksum MSB
  send_command_buff[7] = checksum.bytedata[0]; //checksum LSB
  
  send_command_buff[8] = '*';
  
  for(i = 0; i < NO_PACKET_LEN; i++)
  {
    Serial.print(send_command_buff[i]);
  }
}

void serialEvent()
{
  Serial.print("test1");
  if(Serial.available() > 0)
  {
      Serial.readBytes(buff, NO_PACKET_LEN);
      Serial.print("test2");
      int check = 0;
        
      if((buff[0]=='#') && (buff[8]=='*') && (buff[1]=='I'))
      {
        for(int i = 1; i < 6; i++) check += buff[i];
        checksum.data = check;
        Serial.write("int");
        if(checksum.bytedata[0] == buff[7] && checksum.bytedata[1] == buff[6])
        {
          m_int_test.bytedata[1] = buff[2];
          m_int_test.bytedata[0] = buff[3];
          Serial.println(m_int_test.data);
        }
        else
          Serial.println("wrong");
      }
      
      if((buff[0]=='#') && (buff[8]=='*') && (buff[1]=='F'))
      {
        Serial.print("test3");
        for(int i = 1; i < 6; i++) check += buff[i];
          checksum.data = check;
        
        if(checksum.bytedata[0] == buff[7] && checksum.bytedata[1] == buff[6])
        {
          m_float_test.bytedata[3] = buff[2];
          m_float_test.bytedata[2] = buff[3];
          m_float_test.bytedata[1] = buff[4];
          m_float_test.bytedata[0] = buff[5];
          Serial.print(m_float_test.data);
        }
        else
          Serial.println("w");
      }
      if(buff[8]=='*')
        cnt_rcv = 0;
  }
   
}
