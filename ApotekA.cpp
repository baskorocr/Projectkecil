#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#define MAX 5
using namespace std;

bool ketemu=false, notif=false;
int i, pil,x,pos,pos2,n=0, p=0,JumlahUser,JumlahAgen,tempTopup,tempSaldo;
double topup,beli,setor,tempSaldoAgen[50];
long int pin;
string LogUser,UsernameAgen,UsernameUser,pw,ubahData,tempUser,tempUserAgen[50];
string LogAdmin;


struct user
{
	string nama;
	string pass;
	string alamat;
	string username;
	double saldo;
};

struct admin
{
	string userAdmin;
	int pinAdmin;
};

struct obat
{
	char namaObat[50];
	char keterangan[30];
	double harga;
};

void UbahAdmin(admin &adm);
void BeliObat();
void CekListObat();
void AccTopup();
void TopUp();
void DataAkun(user &usr);
void UbahData();
void MenuAdmin();
void AdminProsesLogin();
void RegisUser();

	
	user usr[50];
	admin adm[10];
	obat obt[50];

string AntrianUser[MAX];
int AntrianSaldoUser[MAX];
int headUser=-1;
int tailUser=-1;

bool IsEmptyUser(){ 
   if(tailUser == -1){
       return true;
   }else{
       return false;
   }
}

bool IsFullUser(){ // FUNGSI UNTUK MENUNJUKAN JIKA TAIL = MAX-1
   if(tailUser == MAX-1){
       return true;
   }else{
       return false;
   }
}

void AntrianMasukUser(string antriUser, int antriSaldoUser){
    if (IsEmptyUser()){
        headUser=tailUser=0;
    }else {
        tailUser++;
    }
    AntrianUser[tailUser]=antriUser;
    AntrianSaldoUser[tailUser]=antriSaldoUser;
}


int main()
{
	
	portal:
	system("cls");
	cout<<"Portal Menu"<<endl;
	cout<<"========================"<<endl;
	cout<<"1. Admin"<<endl;
	cout<<"2. User"<<endl;
	cout<<"Silakan Pilih: ";
	cin>>pil;
	if(pil==1)
	{	
		AdminProsesLogin();
	}
	else
	{

		menu:
			
			system("cls");
			cout<<" ____________________________________________________ "<<endl;
	        cout<<"|                   Apotek Online                    |"<<endl;
	        cout<<"|               Mitra Selamat Sentosa                |"<<endl;
	        cout<<"|            Jln. Tengku Imam Syahid No 5            |"<<endl;
	        cout<<"|____________________________________________________|"<<endl;
	        cout<<"|_____________________Menu User______________________|"<<endl;
	        cout<<"|    1. Pendaftaran User                             |"<<endl;
	        cout<<"|    2. Top Up Saldo                                 |"<<endl;
	        cout<<"|    3. Cek List Obat                                |"<<endl;
	        cout<<"|    4. Beli Obat                                    |"<<endl;
	        cout<<"|    5. Keluar                                       |"<<endl;
	        cout<<"|____________________________________________________|"<<endl;
	        cout<<" Pilihan Anda : "; cin>>pil;
	        
	        if(pil==1)
	        {
				RegisUser();
				goto menu;
			}
			if(pil==2)
	        {
				TopUp();
				goto menu;
				
			}
			if(pil==3)
	        {
	        	
			}
			if(pil==4)
	        {
	        	
			}
			if(pil==5)
			{
				cout<<"Anda Keluar aplikasi";
				ketemu=true;
				main();
			}
		}
	
	
}

void RegisUser()
{ketemu=false;
	lagi:
					system("cls");
					cout<<"Cek Ketersediaan Username : ";
					cin>>UsernameUser;
					for (i=0; i<n; i++)
					{
						if(UsernameUser==usr[i].username)
						{
							ketemu=true;
							
						}
						else
						{
							ketemu=false;
						}
					}
					if(ketemu)
					{
						cout<<"Username anda Sudah terpakai, silakan cari lagi";
						getch();
						goto lagi;
					}
					else
					{	
						cout<<"Username yang anda pilih kosong  dan sudah kami daftarkan"<<endl;
						cout<<"Masukan Nama Anda : ";
						cin>>usr[n].nama;
						cout<<"Masukan Password Akun anda : ";
						cin>>usr[n].pass;
						cout<<"Masukan alamat anda : ";
						cin>>usr[n].alamat;
						JumlahUser=JumlahUser+1;
					}
					n=n+1;
					cout<<n;
					getch();
					usr[i].username=UsernameUser;
}

void AdminProsesLogin()
{
		if(ketemu==false)
		{
			adm[0].userAdmin="admin";
			adm[0].pinAdmin=1234;
			cout<<"Masukan default Username Admin : ";
			cin>>LogAdmin;
			cout<<"Masukan default Pin Admin : ";
			cin>>pin;
			if(LogAdmin==adm[0].userAdmin && pin==adm[0].pinAdmin)
			{	
				system("cls");
				UbahAdmin(adm[0]);
				ketemu=true;
				main();
				
			}
			else
			{
				cout<<"Admin Default salah, silakan Kontak : Developer";
				getch();
				main();
				
			}
		}
		else
		{
			system("cls");
			cout<<"Login Admin"<<endl;
				cout<<"========================"<<endl;
		        cout<<"Masukan Username : ";
	        	cin>>LogAdmin;
	        	cout<<"Masukan Pin : ";
	        	cin>>pin;
	        	
		        	if(LogAdmin==adm[0].userAdmin && pin==adm[0].pinAdmin)
		        	{
		        		kembali:
		        		system("cls");
		        		MenuAdmin();
		        		
					}
					else
					{
						cout<<"gagal";
						main();
					}
					
					
		}
}

void UbahAdmin(admin &adm)
{	
	cout<<"Ubah data Admin"<<endl;
	cout<<"========================"<<endl;
	cout<<"Masukan Username Anda : ";
	cin>>adm.userAdmin;
	cout<<"Masukan Pin Admin: ";
	cin>>pin;		
	adm.pinAdmin=pin;
}

void DataAkun(user &usr)
{
	cout<<"Nama : "<<usr.nama<<endl;
}

void TopUp()
{
	cout<<"Masukan Username Anda : ";
	cin>>UsernameUser;
	cout<<"Masukan Password Anda : ";
	cin>>pw;
	for(i=0; i<n; i++)
	{
		if(UsernameUser==usr[i].username && pw==usr[i].pass)
		{
			notif=true;
			cout<<"Masukan Nominal Saldo TopUp : ";
			cin>>setor;
			pos=i;
			break;
		}
		else
		{
			notif=false;
		}
	}
	if(notif)
	{
		tempUser=UsernameUser;
		tempSaldo=setor;
		AntrianMasukUser(tempUser, tempSaldo);
		tempTopup=tempTopup+1;
		
		cout<<"Silakan melakukan konfirmasi pembayaran ke Agen";
		getch();
	}
	else
	{
		cout<<"Akun anda tidak ditemukan";
	}
}
void AccTopup()
{
	if(IsEmptyUser())
	{	
		cout<<"Tidak ada Permintaan saldo";
		getch();
	}
	else
	{
			
	     		for(i=headUser; i<=tailUser; i++)
				{
					cout<<"Username : "<<AntrianUser[i]<<endl;
					cout<<"Saldo yang dipesan : "<<AntrianSaldoUser[i]<<endl;
				}
				cout<<"========================"<<endl;
				
					cout<<"Masukan Username yang ingin di TopUp : ";
					cin>>UsernameUser;				
					for(int a=headUser; a<=tailUser; a++)
					{	
							if(UsernameUser==AntrianUser[a])
							{	int pos3=a;
									for(i=0; i<n; i++)
									{
										if(UsernameUser==usr[i].username)
										{
											notif=true;
											pos=i;
											break;
										}
										else
										{
											notif=false;
										}
									}
									if(notif)
									{
										
										usr[pos].saldo=usr[pos].saldo+AntrianSaldoUser[pos3];
										cout<<"saldo Berhasil Di TopUp"<<endl;
										cout<<"Jumlah saldo yang User : Rp."<<usr[pos].saldo<<endl;
										getch();
									}
									else
									{
										cout<<"Username tidak ada";
										break;
									}
								//Antrian Keluar
									
					            AntrianUser[pos3]=AntrianUser[pos3+1];
					            AntrianSaldoUser[pos3]=AntrianSaldoUser[pos3+1];
						        if(tailUser == -1){
						            headUser = -1;
	            							        }									
							}				
					}
					tailUser--;
				
			
		
		
	}
	
}
void CekListObat()
{
	
}
void BeliObat()
{
	
}

void MenuAdmin()
{			
			admin:
			system("cls");
			cout<<" ____________________________________________________ "<<endl;
	        cout<<"|                   Apotek Online                    |"<<endl;
	        cout<<"|               Mitra Selamat Sentosa                |"<<endl;
	        cout<<"|            Jln. Tengku Imam Syahid No 5            |"<<endl;
	        cout<<"|____________________________________________________|"<<endl;
	        cout<<"|_____________________Menu Admin_____________________|"<<endl;
	        cout<<"|    1. Acc TopUp Saldo                              |"<<endl;
	        cout<<"|    2. Input Obat                                   |"<<endl;
	        cout<<"|    3. Acc pesan Obat                               |"<<endl;
			cout<<"|    4. Keluar                                       |"<<endl;	        
	        cout<<"|____________________________________________________|"<<endl;
	        cout<<endl;
	        cout<<"Masukan Pilihan anda : ";
	        cin>>pil;
	        if(pil==1)
	        {
	        	AccTopup();
	        	goto admin;
			}
			if(pil==2)
	        {
	        	
			}
			if(pil==3)
	        {
	        	
			}
			if(pil==4)
	        {
	        	getch();
	        	main();
			}


}