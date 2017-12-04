import './libhello.dart';
import 'dart:io';
import 'dart:async';

void main() {
   capp_init();
   while(capp_isQuit() == 0) {
    capp_enterFrame();
    sleep(const Duration(milliseconds:100));
   }
}

main2() async {
   capp_init();

   for(int i=0;i<5*10;i++) {
    capp_enterFrame();
    await new Future.delayed(const Duration(milliseconds:100));
   }
}
