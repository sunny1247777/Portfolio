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
				cout<<"�п�J�j��0�����B"<<endl;
				return;				
			}
			else{
				Money+=m;
				cout<<"eCash: �z�s�F"<<m<<"��"<<endl;
			}			
		}
				 
		void pay(int m){
			
			if(m<=0){
				cout<<"�п�J�j��0�����B"<<endl;
				return;				
			}
			
			else if(Money<m){
				cout<<"eCash: �z��������"<<endl; 
				return;
			}
			else{
				Money-=m;
				cout<<"eCash: �z��F"<<m<<"��"<<endl;
			}
		}
		
		void display()
		{
			cout<<"eCash: �z�|��"<<Money<<"��"<<endl;
			
		}
		void login(){
			
			cin>>ID; 
			FILE *f1=fopen(ID,"r");
			if (f1 == NULL){
				cout<<"eCash: �b�����s�b, �Ĥ@���ϥ�!"<<endl;
				
				
				
			}
		    else{
		    	fscanf(f1,"%d",&Money);
			    cout<<"eCash: �b���}�ҧ���! "<<endl;
			    fclose(f1);
			    			    
			}
		}
		
		void logout(){
			cout<<"eCash: �b���n�X�A�w�s��!"<<endl; 
			
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
	cout<<"=== �w��ϥ�eCash ==="<<endl;
	cout<<"eCash: �п�J�z���b��:"; 
		 
	p1.login();
	cout<<"�z�n�A�п�ܶ���:"<<endl; 
	
	cout<<"s: �x��"<<endl;
	cout<<"p: ���O"<<endl;
	cout<<"d: �d�߾l�B"<<endl;
	cout<<"q: ���}"<<endl;
	
	
	while(1){
		cin>>op;	
		switch(op){
			case 's':
				cout<<"�п�J�x�s���B:"<<endl;
				cin>>x;
				p1.store(x);
				break;
			case 'p':
				cout<<"�п�J���O���B:"<<endl;
				cin>>x;
				p1.pay(x);
				break;
			case 'd':
				p1.display();
				break;
			case 'q':
				p1.logout();
				cout<<"���¡AByeBye!"<<endl;
				return 0;
			default:
				cout<<"Sorry�A�L���\��"<<endl;
				break;
		
	    }
	    system("pause");
		system("cls");
    }
			
	return 0;
}
