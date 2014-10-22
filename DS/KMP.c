//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct String {
//    char *base;
//    int length;
//}String;
//
///**
// *  模式匹配算法思路:
// *
// *      1) 计算匹配串key的next[]数组
// *          (
// *               计算适配字符的next[j]值:
// *                  1. 字符串:  bread'适配字符'
// *                  2. 所有前缀:   b, br, bre, brea, bread (除开最后的适配字符)
// *                  3. 所有后缀:   read, ead, ad, d         (除开最开始的字符)
// *            )
// *
// *
// *      2) 当前字符匹配失败时, 匹配串key的 ( 移动位数 = 已匹配的字符数 - 对应的部分匹配值 )
// *
// */
//
//
///**
// *   获得key匹配串的next[]
// */
//void getNext(String str, int next[]) {
//    
//    int i = 0, j = -1;
//    next[0] = -1;
//    
//    while (i < str.length) {
//        
//        if (j == -1 || str.base[i] == str.base[j]) {
//            i++;
//            j++;
//            next[i] = j;
//            
//        }else {
//            j = next[j];
//        }
//    }
//}
//
