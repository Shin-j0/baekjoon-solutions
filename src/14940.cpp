#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
class spot{
public:
	int x,y;
	spot(): x{x}, y{y}{}
	spot(const spot & s){
		x = s.x;
		y = s.y;
	}
	void set(int x,int y){
		this->x = x;
		this->y = y;
	}
	void Print(){
		cout << "( "<<x<<", "<< y<<")"<<endl;
	}
};
int **Array;
int width,length;

bool check_index(spot index){
	if((index.x >= 0 && index.x < width) && (index.y >= 0 && index.y < length))
		return 1;
	return 0;
}


int main(void){
	queue<spot> que1;
	queue<spot> que2;
	spot temp, temp_arr[4];
	int index[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };


	int value;

	cin >> length >> width;
	Array = new int*[length];
	for(int i=0; i<length; ++i){
	    Array[i] = new int[width];
	}

	int result = 0;

	for(int y = 0; y<length; ++y){
		for(int x = 0; x<width; ++x){
			cin >> value;
			Array[y][x] = value;
			if(value==0) {
				Array[y][x] = 0;
			}
			else if(value==2){
				temp.set(x,y);
				Array[y][x] = 0;
				que1.push(temp);
			}
			else{
				Array[y][x] = -1;
			}
		}
	}

	while(!que1.empty()){
		result ++;
		while(!que1.empty()){
			temp = que1.front();

			for(int i=0;i<4;++i){
				temp_arr[i].set(temp.x + index[i][0],temp.y + index[i][1]);

				if(check_index(temp_arr[i])){
					if(Array[temp_arr[i].y][temp_arr[i].x] != -1) continue;
					Array[temp_arr[i].y][temp_arr[i].x] = result;
					que2.push(temp_arr[i]);
				}
			}

			que1.pop();
		}
		que1 = que2;
		while(!que2.empty())
			que2.pop();
	}
	for(int y = 0; y<length; ++y){
		for(int x = 0; x<width; ++x)
			cout<<Array[y][x]<< " ";
		cout << endl;
	}
}
