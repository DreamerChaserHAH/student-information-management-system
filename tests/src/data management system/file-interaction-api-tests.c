#include <assert.h>

int add(int a, int b){
    return a + b;
}

void test_add(){
    int result = add(2,3);
    assert(result == 5);
}

int main(){
    test_add();
    return 0;
}