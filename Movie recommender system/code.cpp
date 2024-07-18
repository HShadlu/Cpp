#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h> 
#include <iostream> 
#include <sstream> 
#include  <windows.h>
using namespace std;

//functions :)
void SetColor(int value);
void displaymovies();
void displayrate();	
void Displaysimilarity();	
void Generaterecommendations();
void ratemovie();
void addorremove();
void removemovie();

///define functons :)
void SetColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}
void menu(){
	int flag=1;
	int sel; //menu selection
	SetColor(15);
	printf("\t\t\t\t    >>>MOVIE RECOMMENDATION SYSTEM<<< \n\n\n \t\t\t\t::::::::WELCOME TO THE MAIN MENU::::::::\n\n1.Display movies\n2.Display ratings\n3.Display similarity between two users\n4.Generate recommendations\n5.Rate a movie\n6.Add/Remove a movie\n7.Exit\n\nEnter your choice:");
	while(flag){
			SetColor(2);
		cin>> sel;
		
		//system("Color 07");
		switch(sel){
		
            case 1:
               //cout<<"1"<<endl;
               displaymovies();
               flag=0;
               break;
            case 2:
               //cout<<"2"<<endl;
               displayrate();	
               flag=0;
               break;
            case 3:
               //cout<<"3"<<endl;
               Displaysimilarity();
               flag=0;
               break;
               
            case 4:
               Generaterecommendations();
               flag=0;
               break;  
			    
           case 5:
               ratemovie();
               flag=0;
               break;    
               
            case 6:
               addorremove();
               flag=0;
               break; 
			case 7:
               //cout<<"7"<<endl;
               system("CLS");
               flag=0;
               	SetColor(15);
               cout<<"you are exited sucsessfuly :)";
               exit(1);
               break;     
            
            default:
            		SetColor(4);
                 cout<<"This oprion is invalid.try again:";
                 break;
            }
		
		
		
	}
	
	
	
	
}

	   
void displaymovies(){
	
	system("CLS");
		SetColor(15);
	printf("--------------\nDisplay movies\n--------------\n\n");
	
	
	
char sel;
int flag=1;	
int c=0;
printf("Movie Id\tyear\tMovie name\n\n--------\t----\t----------\n")	;
  fstream fileObj; /////opeining file to read
  fileObj.open("Movies.txt", ios::in);
  char str[1000]; //place of each line readed
  
  int tab; //number of tab characters
  int linenum=0; //number of lines
  
   while (!fileObj.eof()){
   	string year="";
   	string id="";
   	string name="";
	linenum=linenum+1;
    fileObj.getline(str, 1000);
    
	
	
	for(int i=0;i<100;i++){
    	if(str[i]=='\t'){
    		tab=tab+1;
    		
		}
		if(tab==0){
			id=id+str[i];
			//cout<<id<<endl;
		}
		if( tab==1){             //display Id and name
			name=name+str[i];
			
		}
		if(tab==2 ){ 
		//c=c+1;    //export year
			year=year+str[i];	
			
			}
	    
	    
	}
	
	
    cout<<"   "<<id<<'\t'<<year<<name<<endl;
    tab=0;
    
   	
   	
   }  
   fileObj.close();
   
   while(flag){
   	cout<<"\n  Press 'm' to Main menu,'q' to Quit:";
   	cin>>sel;
   	if(sel=='m'){
   		flag=0;
   		system("CLS");
   		menu();
   		//cout<<"goh to menu";
	   }
	 if(sel=='q'){
	 	system("CLS");
	 	cout<<"you are exited sucsessfuly :)";
        exit(1);
	 }  
   	
   }
  	}


struct user
{ 
int films[61];

 
};   
void displayrate(){
	system("CLS");
		SetColor(15);
	printf("  ----------------\n  Display Ratings\n  ----------------\n\n");
	int inid;
	
	cout<<"Enter user Id:";
	int flag=1;
	while(flag){
			SetColor(2);
		scanf("%d",&inid);
		
		if(inid<51 && inid>0){
			flag=0;
		}
		else{
			//cout<<endl;
				SetColor(4);
			cout<<"This user does not exist,try again:";
			
		}
		
	}
	
		SetColor(15);
//	struct user users[51];
 	printf("\n  Ratings of user%d are:\n\n",inid);
	printf("  Movie Id\tRate\n");
	printf("  --------\t-----\n");
 int rate,filmid,userid,c;
  int intword;
  int found=0;
	// filestream variable file 
	fstream file; 
	string word,filename; 

	// filename of the file 
	filename = "Ratings.txt"; 

	// opening file 
	file.open(filename.c_str()); 

	// extracting words from the file 
	while (file >> word) {
	stringstream sword(word);
	sword >> intword;
	 c++;
		// displaying content 
		if(c%3==1){
			//cout << "userid:";
		///cout << intword << endl;
		userid=intword;
		
		if(inid==userid){
			found=1;
			//cout<<found;
		}
		}
		if(c%3==2){
		//cout << intword*2 << endl;
		//cout << "filmid:";
		//cout << intword << endl;
		filmid=intword;
		if(found){
			cout<<"   "<<filmid<<"\t\t";
		}
		
		}
		if(c%3==0){
		//cout << intword*2 << endl;
	//	cout << "rate:";
		//cout << intword << endl;
		rate=intword;
		if(found){
		
			cout<<rate<<endl;
		}
		found=0;
		//users[userid].films[filmid]=rate;
		//printf("users[%d].films[%d]:%d\n",userid,filmid,users[userid].films[filmid]);
		}
		
		
		
	}
	file.close(); 
	

	
		
	
	
	
	
	flag=1;
	char sel;
	while(flag){
   	cout<<"Press 'r' to Retry,'m' to Main menu,'q' to Quit:";
   	cin>>sel;
   	if(sel=='m'){
   		flag=0;
   		system("CLS");
   		menu();
   		//cout<<"goh to menu";
	   }
	 if(sel=='q'){
	 	system("CLS");
	 	cout<<"you are exited sucsessfuly :)";
        exit(1);
     
	 }  
   	if(sel=='r'){
     	flag=0;
     	system("CLS");
     	displayrate();
     	
	 }   
   }
	
	
	
	
	
}
  
 float mysim(int u,int v){
	
	
	
  int ratearr[51][61]={0};
 
  int rate,filmid,userid,c; //c id counter
  int intword;
	// filestream variable file 
	fstream file; 
	string word,filename; 

	// filename of the file 
	filename = "Ratings.txt"; 

	// opening file 
	file.open(filename.c_str()); 

	// extracting words from the file 
	while (file >> word) {
	stringstream sword(word);
	sword >> intword;
	 c++;
		// displaying content 
		if(c%3==1){
			//cout << "userid:";
		///cout << intword << endl;
		userid=intword;
		}
		if(c%3==2){
		//cout << intword*2 << endl;
		//cout << "filmid:";
		//cout << intword << endl;
		filmid=intword;
		}
		if(c%3==0){
		//cout << intword*2 << endl;
	//	cout << "rate:";
		//cout << intword << endl;
		rate=intword;
		ratearr[userid][filmid]=rate;
		//printf("ratearr[%d][%d]:%d\n",userid,filmid,ratearr[userid][filmid]);
		}
		
		
		
	}
	file.close();
	float sim=0.0;//similarity
	float sum,sum1,sum2;
	for(int i=1;i<61;i++){
		if(ratearr[u][i]>0){
			if(ratearr[v][i]>0){
				
			
		//printf("users[%d].films[%d]:%d\n",inid,i,users[inid].films[i]);
		//printf("filmid:%d --> %d:%d %d:%d \n",i,u,ratearr[u][i],v,ratearr[v][i]);
		sum=sum+( ratearr[u][i]*ratearr[v][i]);
		sum1=(ratearr[u][i]*ratearr[u][i])+sum1;
		sum2=(ratearr[v][i]*ratearr[v][i])+sum2;
		//cout << i << endl;
		
	}
	}
		}
		//cout<<sum<<endl;
		//cout<<sum1<< endl;
		//cout << sum2<< endl;
		sum1=sqrt(sum1);
		sum2=sqrt(sum2);
		 //sim=sum/(sum1) *(sum2);
		 //sum1=sum1*sum2;
		 sim=sum/(sum1*sum2);
		//cout<<sim<<endl;
		//cout<<sum2<< endl;
		//cout<<sim<< endl;
		sum=0;
		sum1=0;
		sum2=0;
		return sim;
	
	
}	
	 
  
void Displaysimilarity(){

	system("CLS");
		SetColor(15);
	printf("  ------------------------------------\n  Display Similarity Between Two Users\n  ------------------------------------\n\n");
	
	
	
	
	int flag=1;
	int u,v;  //first and second userid
	
	
	
	cout<<"Enter first user Id:";
	while(flag){
			SetColor(2);
		cin>>u;
		
		if(u<51 && u>0){
			flag=0;
		}
		else{
			//cout<<endl;
				SetColor(4);
			cout<<"This user does not exist,try again:";
			
		}
		}
			SetColor(15);
	cout<<"Enter second user Id:";
	while(flag==0){
			SetColor(2);
		cin>>v;
		
		if(v<51 && v>0){
			flag=1;
		}
		else{
			//cout<<endl;
				SetColor(4);
			cout<<"This user does not exist,try again:";
			
		}
		}
	//int	u=1;
	//int	v=5;
		SetColor(15);
	printf("\nSimilarity Between  User%d and user%d:%f\n",u,v,mysim(u,v));
	//flag=1;
	char sel;
	while(flag){
   	cout<<"Press 'r' to Retry,'m' to Main menu,'q' to Quit:";
   	cin>>sel;
   	if(sel=='m'){
   		flag=0;
   		system("CLS");
   		menu();
   		//cout<<"goh to menu";
	   }
	 if(sel=='q'){
	 	system("CLS");
	 	cout<<"you are exited sucsessfuly :)";
        exit(1);
     
	 }  
   	if(sel=='r'){
     	flag=0;
     	system("CLS");
     	Displaysimilarity();
     	
	 }   
   }
	
	
	
	//cout<<mysim(u,v)<<endl;
}
	
int displaymovbyid(string id,float max){
	fstream fileObj;
  fileObj.open("Movies.txt", ios::in);
  char str[1000];
  int tab;
  int linenum=0;
  
  while (!fileObj.eof())
  { 
     linenum=linenum+1;
    fileObj.getline(str, 1000);
    string myname="";
  string myyear="";
  string myid="";
	
	
	for(int i=0;i<100;i++){
    	if(str[i]=='\t'){
    		tab=tab+1;
		}
		if( tab==0){
			
			myid=myid+str[i] ;
			}
	    if(tab==1){
	    myname=myname+str[i];
		}
	    if(tab==2){
	    myyear=myyear+str[i];
		}
	}
	tab=0;
    //printf("\n");
    if(id==myid){
    	cout<<" "<<myid<<"\t"<<myyear<<"\t\t";
		
    	printf(" %.2f\t\t",max);
    	cout<<myname<<endl;
    	return 1;
    	
	}
    	
		
	
	
    }
    fileObj.close();
}
		
int indexOfMax(float arr[],int n) {
    if (n == 0) {
        return -1;
    }

    float max = arr[0];
    int maxIndex = 0;

    for (int i = 1; i <= n; i++) {
        if (arr[i] > max) {
            maxIndex = i;
            max = arr[i];
        }
    }

    return maxIndex;
}	

struct unknownfilm
{ 
int id;
float predictrate;

 
};                                 
 
void Generaterecommendations(){
    system("CLS");
    	SetColor(15);
	printf("  ------------------------------------\n  Generate Recommendations\n  ------------------------------------\n\n");
	
	int u,inid;
	int f=1;
    cout<<"Enter user Id:";
		SetColor(2);
        cin>>u;	
/*	while(f){
		SetColor(2);
        cin>>inid;
        
		if(inid>50 || inid<0){
		 SetColor(4);
		cout<<"This user does not exist,try again:";
		}
	   else
	   if( inid>0 ||inid<50) {
		    f=0;
	}	
		
	}	*/
		
		
		
	

	unknownfilm unknownfilms[60]={0};
    
    
	
    float simidarr[50]={0};
    float simidarrcp[50]={0};
    float sortedsimid[50]={0};
	for(int i=1;i<=50;i++){
		
		if(0< mysim(u,i) && mysim(u,i)<=1  ){//printf("%.2f\n",sim(2,i));
		simidarr[i]=mysim(u,i);
		simidarrcp[i]=mysim(u,i);
		//printf("%f\n",simidarr[i]);
		}
		
		//printf("%f\n",simidarr[i]);
	}
	for(int i=0;i<50; i++){
	int maxind=indexOfMax(simidarrcp,50);
	
	sortedsimid[i]=maxind;
	
	simidarrcp[maxind]=0;
	}
	int ratearr[51][61]={0};
 
 int rate,filmid,userid,c; //c id counter
  int intword;
	// filestream variable file 
	fstream file; 
	string word,filename; 

	// filename of the file 
	filename = "Ratings.txt"; 

	// opening file 
	file.open(filename.c_str()); 

	// extracting words from the file 
	while (file >> word) {
	stringstream sword(word);
	sword >> intword;
	 c++;
		// displaying content 
		if(c%3==1){
			//cout << "userid:";
		///cout << intword << endl;
		userid=intword;
		}
		if(c%3==2){
		//cout << intword*2 << endl;
		//cout << "filmid:";
		//cout << intword << endl;
		filmid=intword;
		}
		if(c%3==0){
		//cout << intword*2 << endl;
	//	cout << "rate:";
		//cout << intword << endl;
		rate=intword;
		ratearr[userid][filmid]=rate;
		//printf("ratearr[%d][%d]:%d\n",userid,filmid,ratearr[userid][filmid]);
		}
		
		
		
	}
	file.close();
	
	for(int i=1;i<61;i++){
		unknownfilms[i].predictrate=0;
		if(ratearr[u][i]==0){
			///predict:
			float result=0.00;
			float s1=0.00;
			float s2=0.00;
			int v;
			//printf("filmid=%d\t",i);
			
			for(int j=1;j<8;j++){
			v=sortedsimid[j];
			
			
			
			s1=s1+(ratearr[v][i]*simidarr[v]);
			
			s2=s2+ simidarr[v];
			//printf("ratev:%d ,sim(2,v):%f s1:%f s2:%f \n",ratearr[v][i],simidarr[v],s1,s2);
			}
			//printf("s2 before:%d",s2);
			//s2=sqrt(s2);
			result=s1/s2;
			
			
			//uncounter++;
			unknownfilms[i].id=i;
			unknownfilms[i].predictrate=result;
			
			//printf("%.2f\n",unknownfilms[i].predictrate);
			
		//printf("\ns1:%d s2:%d ... for %d rate: %2f \n",s1,s2,i,result);
				} 
				}
			SetColor(15);
			printf("\nTop 3-recommendations for user%d are:\n\n ID\t        YEAR   \t\t PREDICTING RATE \tMOVIENAME\n-----\t       ---------    \t---------------\t\t----------\n\n",u)	;	
		for(int i=0;i<3;i++){
				float max=0.0;
				int maxind=0;
				//cout<<maxind<<endl;
			for (int j = 1; j < 61; j++) {
			
        if (unknownfilms[j].predictrate > max) {
            maxind = j;
            //cout<<maxind<<endl;
            max =unknownfilms[j].predictrate ;
            //cout<<max<<endl;
           }  
		   
		   } unknownfilms[maxind].predictrate=0;
        
        //cout<<maxind<<endl;
			
		 //printf("maxind: %d ,max:%.2f\n",maxind,max);
		 stringstream ss;  
         ss<<maxind;  
         string s;  
          ss>>s;  
		 displaymovbyid(s,max);
		 //printf("\t\t %.2f \n",max);
		}
	
	
	
	
	int flag=1;
	char sel;
	while(flag){
   	//cout<<"Press 'r' to Retry,'m' to Main menu,'q' to Quit:";
   	printf("\n********What do tou want to do?********\na.display all predictions for this user\nb.Retry\nc.back to maun menu\nd.Exit\n\n");
   	SetColor(2);
   	cin>>sel;
   	if(sel=='c'){
   		flag=0;
   		system("CLS");
   		menu();
   		//cout<<"goh to menu";
	   }
	 if(sel=='d'){
	 	system("CLS");
	 	SetColor(15);
	 	cout<<"you are exited sucsessfuly :)";
        exit(1);
     
	 }  
   	if(sel=='b'){
   		Generaterecommendations();
     	flag=0;
     	system("CLS");
     	//cout<<"rrrrrrrr";
		 //Displaysimilarity();
     	
	 }   
	 if('a'){
	 	
	 	for(int i=0;i<60;i++){
				float max=0.0;
				int maxind=0;
				//cout<<maxind<<endl;
			for (int j = 1; j < 61; j++)
			 {
			
                  if (unknownfilms[j].predictrate > max) {
            maxind = j;
            //cout<<maxind<<endl;
            max =unknownfilms[j].predictrate ;
            //cout<<max<<endl;
           }  
		   
		   } unknownfilms[maxind].predictrate=0;
        
        //cout<<maxind<<endl;
			
		 //printf("maxind: %d ,max:%.2f\n",maxind,max);	
		 if(max>0){
		 stringstream ss;  
         ss<<maxind;  
         string s="";  
          ss>>s;
		  SetColor(15); 	
		 displaymovbyid(s,max);
		 //printf("\t %.2f \n",max);
		 }
		 
		}	
	
	 	
	 	
	 	
	 	
	 	
	 }
}
	
}
	
void delete_line(const char *file_name, int n) 
{ 
	// open file in read mode or in mode 
	ifstream is(file_name); 

	// open file in write mode or out mode 
	ofstream ofs; 
	ofs.open("temp.txt", ofstream::out); 

	// loop getting single characters 
	char c; 
	int line_no = 1; 
	while (is.get(c)) 
	{ 
		// if a newline character 
		if (c == '\n') 
		line_no++; 

		// file content not to be deleted 
		if (line_no != n) 
			ofs << c; 
	} 

	// closing output file 
	ofs.close(); 

	// closing input file 
	is.close(); 

	// remove the original file 
	remove(file_name); 

	// rename the file 
	rename("temp.txt", file_name); 
} 
 void writerate(int uid,int fid,int rate){
 	
 	std::ofstream ofs;
    ofs.open ("Ratings.txt", std::ofstream::out | std::ofstream::app);

    ofs << "\n";
    ofs << uid;
    ofs << '\t';
    ofs << fid;
    ofs << '\t';
    ofs << rate;
    ofs.close();

 	
 	
 	
 }
 int searchmovieline(int fid,int uid){
  int c=0;
  int ufound=0;
  int intword;
	// filestream variable file 
	fstream file; 
	string word,filename; 

	// filename of the file 
	filename = "Ratings.txt"; 

	// opening file 
	file.open(filename.c_str()); 
    int linenum=0;
	// extracting words from the file 
	while (file >> word) {
	stringstream sword(word);
	sword >> intword;
	 c++;
		// displaying content 
		if(c%3==1){
			//cout << "userid:";
		//cout << intword << endl;
		if(intword==uid){
		ufound=1;
	
		}
		//userid=intword;
		}
		if(c%3==2){
		//cout << intword*2 << endl;
		//cout << "filmid:";
		//cout << intword << endl;
		if(intword==fid && ufound==1 ){
			//cout<<linenum;
			file.close();
			return linenum;
		}
		//filmid=intword;
		}
		if(c%3==0){
		//cout << intword*2 << endl;
	//	cout << "rate:";
		//cout << intword << endl;
		linenum=linenum+1;
		ufound=0;
		//rate=intword;
		//users[userid].films[filmid]=rate;
		//printf("users[%d].films[%d]:%d\n",userid,filmid,users[userid].films[filmid]);
		}
		
		
		
	}
	file.close(); 
	return -1;
    
  }	
  
 int searchmovbyid(string id){  	
 fstream fileObj;
  fileObj.open("Movies.txt", ios::in);
  char stri[500];
  int linenum=0;
  
  while (!fileObj.eof())
  {
  	int tab=0;
  	string foundid="";
  	
  	
  	
    fileObj.getline(stri, 500);
    linenum=linenum+1;
      
	    for(int i=0;i<100;i++){
	    	if(stri[i]=='\t'){
	    		
    		tab=tab+1;	}
	    	if(tab==0){
	    			foundid=foundid+stri[i];
			}
	    
	    	
    	
		}
	//extractIntegerWords(str);
	  //cout<<name<<endl; 
	  if(foundid==id){
	  	
	  	
	  	fileObj.close();
	  	//delete_line("mov.txt", linenum);
	  	return 1;
	  }
	  //name=""; 
	}
	
	return 0;
	
 	
 	
 	
 } 
void ratemovie(){

		
system("CLS");
SetColor(15);
printf("  -------------\n  Rate a Movie\n  -------------\n\n");	
printf("Enter the information Bellow\n============================\n");
int uid,fid,rate;
string idd;
char save;
//int fid,rate,uid,
cout<<"User Id:"<<endl;
SetColor(2);
cin>>uid;
SetColor(15);
cout<<"Film Id:"<<endl;
SetColor(2);
cin>>idd;
SetColor(15);
cout<<"Rating(1-5):"<<endl;
SetColor(2);
cin>>rate;
SetColor(15);
printf("\n============================\n");
cout<<"Do you want to save record?(y,n)"<<endl;
SetColor(2);
cin>>save;
stringstream sword(idd);
sword >> fid;


int flag=1;

	if(save=='n'){
	goto label;
		
	}
	if(save=='y'){
		//cout<<"hiiiiiiii";
	    if(uid>50 || uid<=0){
	    	SetColor(4);
	    	cout<<"Tis user id does not exist"<<endl;
	    	goto label;
		}	
		if(searchmovbyid(idd)==0){
			SetColor(4);
	    	cout<<"This movie id does not exist"<<endl;
	    	goto label;
		}
		if(rate>5 || rate<1){
			SetColor(4);
			cout<<"This rating is not valid.(only between 1to5)"<<endl;
			goto label;
			
		}
		
		
		
	}
	if(searchmovieline(fid,uid)==-1){
		writerate(uid,fid,rate);
		SetColor(15);
		cout<<"new record done!"<<endl;
	}
	else{
		
	delete_line("Ratings.txt", searchmovieline(fid,uid)+1); 
	writerate(uid,fid,rate);
	SetColor(15);
	cout<<"record done!"<<endl;
	}
	
	
	

 
label:
	
    flag=1;
	char sel;
	while(flag){
		SetColor(15);
   	cout<<"\n\n  Press 'r' to Retry,'m' to Main menu,'q' to Quit:";
   	cin>>sel;
   	if(sel=='m'){
   		flag=0;
   		system("CLS");
   		menu();
   		//cout<<"goh to menu";
	   }
	 if(sel=='q'){
	 	system("CLS");
	 	cout<<"you are exited sucsessfuly :)";
        exit(1);
     
	 }  
   	if(sel=='r'){
     	flag=0;
     	system("CLS");
     	ratemovie();
	 }   
   }
	
 

	
	
	
	
	
}	


int searchfilmname(string fname){
	
	
  fstream fileObj;
  fileObj.open("Movies.txt", ios::in);
  char stri[500];
  fname='\t'+fname;
  
  while (!fileObj.eof())
  {
  	int tab=0;
  	string name="";
  	string foundid="";
  	
  	
    fileObj.getline(stri, 500);
    
      
	    for(int i=0;i<100;i++){
	    	if(tab==0){
	    			foundid=foundid+stri[i];
			}
	    
	    	if(stri[i]=='\t'){
	    		
    		tab=tab+1;	}
    		if(tab==1)
	    	name=name+stri[i];
		}
	//extractIntegerWords(str);
	  //cout<<name<<endl; 
	  if(name==fname){
	  	fileObj.close();
	  	return 1;
	  }
	  //name=""; 
	}
	fileObj.close();
	return 0;
	
}
void addmov(int id,string name,int year){
 
 	std::ofstream ofs;
    ofs.open ("Movies.txt", std::ofstream::out | std::ofstream::app);

    ofs << "\n";
    ofs << id;
    ofs << "\t";
    ofs << name;
    ofs << "\t";
    ofs << year;
    ofs<<"\t";
    SetColor(15);
    
    printf("Record sucsesssfuly(ID=%d)",id);
    ofs.close();

 	
 	
 	
 }

void addnewmovie(){
	system("CLS");
	SetColor(15);
	printf("  ----------------------\n  Add a New Movie\n  ----------------------\n\n");
	printf("Enter the information Bellow\n============================\n");
	int sysid=(rand() % (100- 60) )+ 60;
	string name; 
    char save;
    int year;
    
    cout<<" name:";
    cin.sync();
    SetColor(2);
    getline(cin,name);
    //cin.sync();
    SetColor(15);
    cout<<" year:";
    SetColor(2);
    cin>>year;
    
    cin.sync();
    SetColor(15);
    printf("============================\n\n");
    cout<<"Do you whant to save?";
    SetColor(2);
    cin>>save;
    cin.sync();
    
    //getline(cin,name);
	if(save=='n'){
		goto label;
	}
	if(searchfilmname(name) ){
		SetColor(4);
    		cout<<"\n  this film is already exist!"<<endl;
    		goto label;
		}
    if(save=='y' &&   searchfilmname(name)==0){
    
	addmov(sysid,name,year);
	}
    
    
    
    
    		
	
	
	
	


label:
    int flag=1;
	char sel;
	while(flag){
		SetColor(15);
   	cout<<"\n\n  Press 'r' to Retry,'m' to Main menu,'q' to Quit:";
   	cin>>sel;
   	if(sel=='m'){
   		flag=0;
   		system("CLS");
   		menu();
   		//cout<<"goh to menu";
	   }
	 if(sel=='q'){
	 	system("CLS");
	 	cout<<"you are exited sucsessfuly :)";
        exit(1);
     
	 }  
   	if(sel=='r'){
     	flag=0;
     	//system("CLS");
     	addnewmovie();
     	//goto label;
	 }   
}


}

int removemovbyid(string id){  	
 fstream fileObj;
  fileObj.open("Movies.txt", ios::in);
  char stri[500];
  int linenum=0;
  
  while (!fileObj.eof())
  {
  	int tab=0;
  	string foundid="";
  	
  	
  	
    fileObj.getline(stri, 500);
    linenum=linenum+1;
      
	    for(int i=0;i<100;i++){
	    	if(stri[i]=='\t'){
	    		
    		tab=tab+1;	}
	    	if(tab==0){
	    			foundid=foundid+stri[i];
			}
	    
	    	
    	
		}
	//extractIntegerWords(str);
	  //cout<<name<<endl; 
	  if(foundid==id){
	  	
	  	
	  	fileObj.close();
	  	delete_line("Movies.txt", linenum);
	  	return 1;
	  }
	  //name=""; 
	}
	
	return 0;
	
 	
 	
 	
 }
 

 int removebyname(string fname){
 	//string myid=searchfilmname(name);
 	//delete_line("mov.txt", stoi(myid));
 	fstream fileObj;
  fileObj.open("Movies.txt", ios::in);
  char stri[500];
  fname='\t'+fname;
  int linenum=0;
  
  while (!fileObj.eof())
  {
  	int tab=0;
  	string name="";
  	string foundid="";
  	
  	
    fileObj.getline(stri, 500);
    linenum=linenum+1;
      
	    for(int i=0;i<100;i++){
	    
	    
	    	if(stri[i]=='\t'){
	    		
    		tab=tab+1;	}
    		if(tab==1)
	    	name=name+stri[i];
		}
	//extractIntegerWords(str);
	  //cout<<name<<endl; 
	  if(name==fname){
	  	
	  	fileObj.close();
	  	delete_line("Movies.txt", linenum);
	  	return 1;
	  }
	  //name=""; 
	}
	
	return 0;
 	
 }



void removemovie(){
	
	system("CLS");
	SetColor(15);
	printf("  ----------------------\n  Remove a  Movie\n  ----------------------\n\n");
	printf("================Remove by Name or Id ?============\na.By name\nb.By ID\n\nyour choice:");
	int flag=1;
	char sel;
	while(flag){
   	SetColor(2);
   	cin>>sel;
   	if(sel=='a'){
   		flag=0;
   		SetColor(15);
   		printf("Enter the name of the movie:");
   		string name="";
   		char save;
   		cin.sync();
   		SetColor(2);
        getline(cin,name);
        SetColor(15);
        printf("\n Are you sure,you want to delete this movie ? : ");
        SetColor(2);
        cin>>save;
        if(save=='y'){
        		if(removebyname(name)){
        			SetColor(15);
   			cout<<"\nThe record was sucsessuly removed!";
   			goto label;
		   }
		else   {
			SetColor(4);
			cout<<"\nThis movie does not exist";
			goto label;	}
			
			
       	}
       if(save=='n'){
       	goto label;
	   } 	
   	
	   }
	 if(sel=='b'){
	 	flag=0;
	 	SetColor(15);
	 	printf("\nEnter movie ID:");
        string id;
        SetColor(2);
        cin>>id;
        SetColor(15);
        cout<<"\n Are you sure,you want to delete  Movie "<<id<<"?:";
        char save;
        SetColor(2);
        cin>>save;
        if(save=='y'){
        		if(removemovbyid( id)){
            SetColor(15);
   			cout<<"\nThe record was sucsessuly removed!";
   			goto label;
		   }
		        else   {
		        	SetColor(4);
			        cout<<"\nThis movie does not exist";
			        goto label;	}
			
			
       	}
       if(save=='n'){
       	goto label;
	   } 	
        
	 }  
   }
 label:
    flag=1;
	 sel;
	while(flag){
		SetColor(15);
   	cout<<"\n\n  Press 'r' to Retry,'p'to Previous,'m' to Main menu,'q' to Quit:";
   	cin>>sel;
   	if(sel=='m'){
   		flag=0;
   		system("CLS");
   		menu();
   		//cout<<"goh to menu";
	   }
	 if(sel=='q'){
	 	system("CLS");
	 	cout<<"you are exited sucsessfuly :)";
        exit(1);
     
	 }  
	 if(sel=='p'){
	 	flag=0;
	 	addorremove();
	 	
	 }
   	if(sel=='r'){
     	flag=0;
     	//system("CLS");
     removemovie();
     	//goto label;
	 }   
}
    
	
	
}
	
	
	

void addorremove(){
	system("CLS");
	SetColor(15);
	printf("  ----------------------\n  Add/Remove a Movie\n  ----------------------\n\n");
	int flag=1;
	char sel;
	while(flag){
   	//cout<<"Press 'r' to Retry,'m' to Main menu,'q' to Quit:";
   	printf("********What do tou want to do?********\na.Add a new movie\nb.Remove a  movie\nc.Back to mann menu\nd.Exit\n");
   	SetColor(2);
   	cin>>sel;
   	if(sel=='c'){
   		flag=0;
   		system("CLS");
   		menu();
   		//cout<<"goh to menu";
	   }
	 if(sel=='d'){
	 	system("CLS");
	 	SetColor(15);
	 	cout<<"you are exited sucsessfuly :)";
        exit(1);
     
	 }  
   	if(sel=='b'){
     	flag=0;
     	system("CLS");
     	removemovie();
		 //Displaysimilarity();
     	
	 }   
	 if('a'){
		flag=0;
		addnewmovie();
	}
		
	}
	
	
	
	
	
}		
	
	
 
int main(){
	
menu();


     
	
	return 0;
}
