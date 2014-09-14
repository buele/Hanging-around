import java.util.*;

class JniExample {
  native String getString();
  native float getFloat();
  static {
    System.loadLibrary("nativelib");
  }

  public static void main(String args[]) {
    byte buf[];
    JniExample example=new JniExample();
   System.out.print(example.getString());
   System.out.print(example.getFloat());
  }
}

