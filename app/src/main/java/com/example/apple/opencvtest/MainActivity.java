package com.example.apple.opencvtest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

  static {
    System.loadLibrary("native-math");
  }

  private native int addFromCpp(int a, int b);

  @Override protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);

    // Example of a call to a native method
    TextView tv = findViewById(R.id.sample_text);
    tv.setText("" + addFromCpp(3, 5));
  }
}
