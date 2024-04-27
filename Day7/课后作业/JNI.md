1.   MainActivity.java中添加

     ```java
     TextView tv2 = binding.sampleText2;
     tv2.setText(Integer.toString(add(5, 10)));
     
     public native int add(int a, int b);
     ```

     ![image-20240426221424254](./image-20240426221424254.png)

2.   在`native-lib.cpp`中添加`add()`函数

     ![image-20240426221546059](./image-20240426221546059.png)

3.   结果

     ![image-20240426221634119](./image-20240426221634119.png)