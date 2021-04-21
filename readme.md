C++ 动态字符串
=============
dynamicString.hpp
-------------------

### 基本信息
dynamicString实现了C++不定长度的字符串，并且提供了一些函数来对其进行操作  
  
### 内容
#### dstring
dynamicString类型，包含了所有功能。
#### dstring 中的成员  
  

##### content
    char* content = new char[1];
类型：`private`&emsp;`char*`  
一个指向对象字符串的指针, 用来告诉函数要操作的目标字符串在内存中的什么位置。  
  
安全起见，我们禁止外界更改content指针的值。所以将其定义为private
##### length
    int length = 0;  
类型：`private`&emsp;`int`  
用于记录字符串长度。对内防止越界，对外返回长度。  
  
为避免length被意外更改，我们也不允许外部访问它，所以将其定义为private。
  
*若想得到字符串长度，请使用成员中的getLength()函数。
##### free
    int free = 0;
类型：`private`&emsp;`int`  
int类型，用于记录剩余空间。当字符串为静态字符串时，用于记录剩余空间；当字符串为动态
时，始终为0，且没有鸟用。
  
为避免free的被意外缩小，我们不允许外部访问访问该变量，因此定义为private
  
*若想增大空间，请使用speace()函数；若要查询剩余空间，请使用freeSpeace()函数。
##### dynamic
    bool dynamic = true;
类型：`public`&emsp;`bool`  
bool类型，标记字符串为动态/静态。  
设置为true时，字符串为动态；设置为false时，字符串为静态。默认为动态。  
  
某些情况下，我们可能不希望字符串为动态，当同时又想要使用dstring的功能，那么就可以手动
将其设置为false，当作静态字符串使用。
##### function: add()
    int add(const char* buff_new);
类型：`public`&emsp;`int`  
用途：  
&emsp;向字符串尾部追加字符串  
参数：  
&emsp;一个参数：`const char* buff_new`  
&emsp;用于传递要追加的字符串  
返回值：  
&emsp;int类型。返回0为成功；返回1为失败
##### function: speace()
	int speace(int size);
类型：`public`&emsp;`int`
用途：  
&emsp;当字符串为静态时，用于申请空间；当字符串为动态时莫得用。  
参数：  
&emsp;一个参数：`int size`  
&emsp;表示需要创建的空间大小  
返回值：  
&emsp;int类型。返回0为申请成功；返回1为申请失败。
##### function: write()
	int write(const char* buffer);
类型：`public`&emsp;`int`  
用途：  
&emsp;用于写入字符串（会覆盖原有的内容）  
参数：  
&emsp;一个参数：`const char* buffer`  
&emsp;用于传递需要写入的字符串  
返回值：  
&emsp;int类型。返回0成功；返回1失败。
##### function: remove()
	void remove();
类型: `public`&emsp;`void`  
用途:  
&emsp;用于删除字符串
  
因为使用了动态内存分配，且字符串直接存储在内存中，由指针进行操作，没有进行任何封装。
所以使用完毕后应当在合适的位置用这个函数删除分配过的空间。  
##### function: subString()
	dstring subString(int beginning, int length); 
类型: `public`&emsp;`void`  
用途：  
&emsp;用于从字符串中截取一部分。  
参数：  
&emsp;两个参数：`int beginning` `int length`  
&emsp;1. 表示启始位置（的下标）  
&emsp;2. 表示截取长度（单位：字节）  
返回值：  
&emsp;dstring类型。返回截取的字符串
##### function: stringLocation()
	char* stringLocation();
类型: `public`&emsp;`char*`  
用途：  
&emsp;用于查询动态字符串在内存中的位置（把动态字符串转换为char*类型（C标准字符串类型））  
返回值：  
&emsp;char *类型。返回字符串在内存中的地址。
##### function: getLength()
	int getLength();
类型: `public`&emsp;`int`  
用途：  
&emsp;查询字符串长度。  
返回值：  
&emsp;字符串长度。
##### function: freeSpeace()
	int freeSpeace();
类型: `public`&emsp;`int`  
用途：  
&emsp;查询静态字符串的剩余空间。
返回值：  
&emsp;返回剩余空间  

*******
注意事项
=======
1. 编译需要使用--std=c++17才能通过
2. 使用完毕后应当在合适位置将变量删除，否则会造成内存泄露
3. 不建议你访问设置为private的内容，因为之所以这么做是有原因的
4. dstring类型在namespace std中，所以不能直接访问。记得加上using namespace std;
***********************************
# <center>Thanks for Reading</center>  
***********************************
