package com.example.heif;

import android.os.Environment;
import java.io.File;
import java.io.FileInputStream;

/**
 * Created by apple on 2017/12/18.
 */

public class HEIFUtils {
  static {
    System.loadLibrary("heif");
  }

  public native String redHEIF(String fileName);


  public String test() {
    String path = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS)
        + "/IMG_0345.HEIC";
    File file = new File(path);
    if (file.exists()) {
      return redHEIF(path);
    } else {
      return "文件不存在";
    }
  }
}
