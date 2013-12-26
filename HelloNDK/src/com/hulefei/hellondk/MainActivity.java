package com.hulefei.hellondk;

import android.os.Bundle;
import android.widget.TextView;
import android.app.Activity;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		TextView NDKText = (TextView) findViewById(R.id.txtTitle);
		NDKText.setText(stringFromJNI());
	}

	public native String stringFromJNI();

	static {
		System.loadLibrary("native");
	}
}
