library libhello;

import 'dart-ext:hello';
import 'dart:isolate';

int capp_enterFrame() native "capp_enterFrame";
int capp_init() native "capp_init";
