int A=4,B=5,C=6,D=7,M=8,N=9,O=10,P=11,I0,I1,I2,I3,equ,a,b,c,d,a0,b0,c0,d0;
String inpt,otpt,m,n,o,p;

void setup() {
  Serial.begin(9600);          

  pinMode(M, OUTPUT);
  pinMode(N, OUTPUT);
  pinMode(O, OUTPUT);
  pinMode(P, OUTPUT);
       
  pinMode(A, INPUT);    
  pinMode(B, INPUT);    
  pinMode(C, INPUT);    
  pinMode(D, INPUT);    

}

void loop() {
 read_input();
 set_output();
 delay(2000);
}

void read_input(){
  a=digitalRead(A);
  if(a==0){
    a0=1;
  }else{
    a0=0;
  }
  
  b=digitalRead(B);
  if(b==0){
    b0=1;
  }else{
    b0=0;
  }
  
  c=digitalRead(C);
  if(c==0){
    c0=1;
  }else{
    c0=0;
  }
  
  d=digitalRead(D);
  if(d==0){
    d0=1;
  }else{
    d0=0;
  }
  
}
void set_output(){
  inpt=String(d)+String(c)+String(b)+String(a);
  equ=((a0*b*d0)+(a*b0*c0*d0)+(b0*c0*d));
  digitalWrite(M,equ);
  m=String(equ);

  equ=((a0*b*c0)+(a*b0*d)+(c*d0));
  digitalWrite(N,equ);
  n=String(equ);

  equ=((a0*b0*c0*d)+(a0*b0*d0)+(b0*c*d)+(a*b));
  digitalWrite(O,equ);
  o=String(equ);

  equ=((a0*b0*c0*d)+(a0*c0*d0)+(a*b0*c*d0)+(b0*c*d)+(b*c0*d)+(b*c*d0)+(a*b*c*d));
  digitalWrite(P,equ);
  p=String(equ);
  otpt=String(p)+String(o)+String(n)+String(m);
  Serial.println(inpt+"--"+otpt);
}
