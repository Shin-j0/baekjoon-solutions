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

	cin >> width >> length;
	Array = new int*[length];
	for(int i=0; i<length; ++i)
	    Array[i] = new int[width];

	int max_count = width * length, count = 0;
	int result = 0;

	for(int y = 0; y<length; ++y){
		for(int x = 0; x<width; ++x){
			cin >> value;
			Array[y][x] = value;
			if(value==0) continue;
			if(value==1){
				temp.set(x,y);
				que1.push(temp);
			}
			max_count--;
		}
	}

	while(max_count > count){
		if(que1.empty()){
			cout << -1 << endl;
			return 0;
		}
		//cout << max_count << " " << count << endl;
		result ++;
		while(!que1.empty()){
			temp = que1.front();
			//temp.Print();

			for(int i=0;i<4;++i){
				temp_arr[i].set(temp.x + index[i][0],temp.y + index[i][1]);
				//temp_arr[i].Print();
				if(check_index(temp_arr[i]) && Array[temp_arr[i].y][temp_arr[i].x] == 0) {
					Array[temp_arr[i].y][temp_arr[i].x] = 1;
					count ++;
					que2.push(temp_arr[i]);
				}
			}

			que1.pop();
		}
		que1 = que2;
		while(!que2.empty())
			que2.pop();
	}
	cout << result << endl;

}
