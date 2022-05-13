# strace example for an Android app

This shows how to use strace to debug an Android app.

This required rebuilding strace as a static binary and commenting out
https://cs.android.com/android/platform/superproject/+/master:external/strace/strace.c;l=1191-1208;drc=c18737608ced60bee17a83c903d61dd5e80f7bef

This still isn't useful for finding deadlocks like I was originally trying to do
because some part of Java is calling futex often enough to make ours difficult
to identify, but this could be useful for other strace workflows.