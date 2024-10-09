#include<iostream>
#include<string>

using namespace std;

class eCash{
	public:
		eCash()
		{
			int Money=0; 
		} 
		
	    ~eCash(){
	    	
		}
		
		void store(int m){
			
			if(m<=0){
				cout<<"請輸入大於0的金額"<<endl;
				return;				
			}
			else{
				Money+=m;
				cout<<"eCash: 您存了"<<m<<"元"<<endl;
			}			
		}
				 
		void pay(int m){
			
			if(m<=0){
				cout<<"請輸入大於0的金額"<<endl;
				return;				
			}
			
			else if(Money<m){
				cout<<"eCash: 您的錢不夠"<<endl; 
				return;
			}
			else{
				Money-=m;
				cout<<"eCash: 您花了"<<m<<"元"<<endl;
			}
		}
		
		void display()
		{
			cout<<"eCash: 您尚有"<<Money<<"元"<<endl;
			
		}
		void login(){
			
			cin>>ID; 
			FILE *f1=fopen(ID,"r");
			if (f1 == NULL){
				cout<<"eCash: 帳號不存在, 第一次使用!"<<endl;
				
				
				
			}
		    else{
		    	fscanf(f1,"%d",&Money);
			    cout<<"eCash: 帳號開啟完成! "<<endl;
			    fclose(f1);
			    			    
			}
		}
		
		void logout(){
			cout<<"eCash: 帳號登出，已存檔!"<<endl; 
			
	        FILE *f1=fopen(ID,"w");
	        fprintf(f1,"%d",Money);
	        fclose(f1);
	        	        
		}
		
	private:	
		int Money=0;
		int m;
		char ID[100];
		FILE *f1;
};

int main()
{
	int x;
	char op;
	eCash p1;
	cout<<"=== 歡迎使用eCash ==="<<endl;
	cout<<"eCash: 請輸入您的帳號:"; 
		 
	p1.login();
	cout<<"您好，請選擇項目:"<<endl; 
	
	cout<<"s: 儲值"<<endl;
	cout<<"p: 消費"<<endl;
	cout<<"d: 查詢餘額"<<endl;
	cout<<"q: 離開"<<endl;
	
	
	while(1){
		cin>>op;	
		switch(op){
			case 's':
				cout<<"請輸入儲存金額:"<<endl;
				cin>>x;
				p1.store(x);
				break;
			case 'p':
				cout<<"請輸入消費金額:"<<endl;
				cin>>x;
				p1.pay(x);
				break;
			case 'd':
				p1.display();
				break;
			case 'q':
				p1.logout();
				cout<<"謝謝，ByeBye!"<<endl;
				return 0;
			default:
				cout<<"Sorry，無此功能"<<endl;
				break;
		
	    }
	    system("pause");
		system("cls");
    }
			
	return 0;
}
