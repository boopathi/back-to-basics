#include<stdio.h>
#include<iostream>
#include<vector>
#include<csignal>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define REP(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REV(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({int64 t;scanf("%ld",&t);t;})
typedef long long int int64;
using namespace std;
void increment_settings(int *key, int r[3]) {
	int notch[8][2] = { 16,16, 4,4, 21,21, 9,9, 25,25, 25,12, 25,12, 25,12 };
	if(key[1] == notch[r[1]][0] || key[1] == notch[r[1]][1])
		FOR(i,2) key[i] = (key[i]+1)%26;
	if(key[2] == notch[r[2]][0] || key[2] == notch[r[2]][1])
		key[1] = (key[1]+1)%26;
	key[2] = (key[2]+1)%26;
}
char simplesub(char ch, string key) {
	return key[ch-65];
}
char rotor(char ch, int r, int offset) {
	string key[16] = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ","AJDKSIRUXBLHWTMCQGZNPYFVOE","BDFHJLCPRTXVZNYEIWGAKMUSQO",
		"ESOVPZJAYQUIRHXLNFTGKDCMWB","VZBRGITYUPSDNHLXAWMJQOFECK","JPGVOUMFYQBENHZRDKASXLICTW",
		"NZJHGRCXMYSWBOUFAIVLPEKQDT","FKQHTLXOCBJSPDZRAMEWNIUYGV",
		// inverses
		"UWYGADFPVZBECKMTHXSLRINQOJ","AJPCZWRLFBDKOTYUQGENHXMIVS","TAGBPCSDQEUFVNZHYIXJWLRKOM",
		"HZWVARTNLGUPXQCEJMBSKDYOIF","QCYLXWENFTZOSMVJUDKGIARPHB","SKXQLHCNWARVGMEBJPTYFDZUIO",
		"QMGYVPEDRCWTIANUXFKZOSLHJB","QJINSAYDVKBFRUHMCPLEWZTGXO" };
	int chcode = (int(ch)-65+26+offset)%26;
	int mapch = (int(key[r][chcode])-65+26-offset)%26;
	string temp("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	return temp[mapch];
}
char enigma(char ch, int key[3], int rotors[3], int ring[3], string plugboard) {
	//plugboard transformation
	ch = simplesub(ch, plugboard);
	//rotor transformations : right to left
	REV(i,3) ch = rotor(ch,rotors[i],key[i]-ring[i]);
	//use reflector B
	ch = simplesub(ch, "YRUHQSLDPXNGOKMIEBFZCWVJAT");
	//inverse rotor transformations : left to right
	FOR(i,3) ch = rotor(ch, rotors[i]+8, key[i]-ring[i]);
	//plugboard transformation
	ch = simplesub(ch, plugboard);
	return ch;
}
int main(){
	int t = GI;
	while(t-->0){
		string plaintext,ciphertext(""),keysettings,ringsettings,plugboardsettings,rotorsettings,dummy;
		cin>>rotorsettings>>ringsettings>>keysettings;
		getline(cin, dummy);
		getline(cin,plugboardsettings);
		getline(cin, plaintext);
		int rotors[3];
		FOR(i,3) rotors[i] = rotorsettings[i]-48-1;

		//store a simple substitution key
		char parr[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
		int len = plugboardsettings.length();
		for(int i=0,j=1; i<len;i+=3,j+=3) {
			char *pos;
			pos = strchr(parr, plugboardsettings[i]);
			int ichar = pos ? pos - parr : -1;
			pos = strchr(parr, plugboardsettings[j]);
			int jchar = pos ? pos - parr : -1;
			char temp = parr[jchar]; parr[jchar]=parr[ichar]; parr[ichar] = temp;
		}
		string plugboard(parr);

		//interpret key and ring settings - convert letters to numbers
		int key[3];
		FOR(i,3) key[i] = int(keysettings[i])-65;
		int ring[3];
		FOR(i,3) ring[i] = int(ringsettings[i])-65;

		//enigma cipher
		int plength = plaintext.length();
		FOR(i,plength) {
			char ch = plaintext[i];
			if(ch == ' ') ciphertext+=ch;
			else {
				increment_settings(key, rotors);
				char got = enigma(ch, key, rotors, ring, plugboard);
				ciphertext += got;
			}
		}
		cout<<ciphertext<<endl;
	}
	return 0;
}