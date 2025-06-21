JSON:JavaScript Object Notation

三种标准类型，分别是: values, objects, arrays
values可以包含字符串、整数、浮点数、布尔值和null
objects就是JSON对象本身，可以和其它类型相连
arrays可以包含values、objects和arrays

example:
{
    "name":"IAmNidhogg",        // value
    "age": 24,                  // value
    "height": 174.5,            // value
    "tag": ["connect", "fight"],  // array
    "enemies": null,            // value
    "valid": true,              // value
    "unit": {                   // object
        "name": "BRIDGES"          // object-value
    }
}

用树来表示JSON，刚好三种标准类型对应三种节点类型，不难发现，首先必有一个object node作为根节点，其次value node必是也节点，
而array node和object node都可以作为父节点。

1 JSON类的实现 myjson.hpp
枚举类型表示节点种类类型: enum class JSONType : short
然后写一个JSON节点类型：class JSONNode
包含：
节点种类
节点后续指向
数组
数值内容——struct value，包含字符串，数值和布尔值

默认构造函数
给定内容构造函数
拷贝构造

拷贝运算符

一些功能函数

下标运算符重载

取值函数



2 工具函数 utility.hpp

3 JSON解析器 

4 JSON序列化
