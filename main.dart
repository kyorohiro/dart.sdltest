import './libhello.dart';
import 'dart:io';
import 'dart:async';

void main() {
   capp_init();
   capp_enterFrame();
   for(int i=0;i<5;i++) {
    capp_enterFrame();
    sleep(const Duration(milliseconds:1000));
   }
}
main2() async {
   await new Future.delayed(const Duration(milliseconds:1000));
   print("B\r\n");

   for(int i=0;i<5;i++) {
    capp_enterFrame();
    await new Future.delayed(const Duration(milliseconds:1000));
   }
}
