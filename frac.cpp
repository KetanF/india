#include<iostream>
#include<algorithm>
#include<vector>

#include <ctime>
#include <cstddef>
using namespace std;

struct Item{
    int value;
    int weight;
    double ratio;
};

bool compare(Item i1, Item i2){
    return i1.ratio>i2.ratio;
}

double fracKnap(int capacity,vector<Item>& items){
    for(auto& item : items){
        item.ratio = static_cast<double>(item.value)/item.weight;
    }

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int remCap = capacity;

    for(const auto& item: items){
        if(remCap>=item.weight){
            totalValue+=item.value;
            remCap-=item.weight;
        }
        else{
            totalValue+= (static_cast<double>(remCap) /item.weight)*item.value;
            break;
        }
    }
    return totalValue;
}

int main(){
    int n,capacity;
    cout<<"Enter Capacity: ";
    cin >> capacity;

    cout<<"Enter no. of Items: ";
    cin >> n;

    vector <Item> items(n);

    cout<<"Enter Weight & Value of Items:\n";
    for(int i=0;i<n;++i){
        cout<<"Item"<<i+1<<": ";
        cin >> items[i].weight >> items[i].value;
    }
    clock_t start_time = clock();
    double maxVal = fracKnap(capacity, items);
    cout<<"Maximum Value: "<<maxVal;

    
    clock_t end_time = clock();
    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    size_t space_complexity = sizeof(int)*2 + sizeof(double)*2 + sizeof(vector<Item>) + sizeof(Item)*n;

    cout << "Elapsed time (seconds): " << elapsed_time << endl;
    cout << "Space complexity (bytes): " << space_complexity << endl;


    return 0;
}