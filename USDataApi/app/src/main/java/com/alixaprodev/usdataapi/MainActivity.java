package com.alixaprodev.usdataapi;

import androidx.appcompat.app.AppCompatActivity;

import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.alixaprodev.usdataapi.utils.NetworkUtils;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.net.URL;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    EditText edcityName;
    Button btnSubmit;
    TextView tvResult;
    String cityName = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);
        edcityName = findViewById(R.id.city_name_et);
        btnSubmit = findViewById(R.id.submit_btn);
        tvResult = findViewById(R.id.result);


        btnSubmit.setOnClickListener(this);
//       tvResult.setText(cityName);
    }

    @Override
    public void onClick(View v) {
        if (v.getId()==R.id.submit_btn){
            cityName= edcityName.getText().toString();

            try {
                queryData(cityName);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    public void queryData(String city) throws IOException {
        URL url= NetworkUtils.buildUrl();
        new DataTask().execute(url);


    }
    public class DataTask extends AsyncTask<URL,Void,String>{


        @Override
        protected String doInBackground(URL... urls) {
            URL url = urls[0];
            String data= null;
            try {
                data = NetworkUtils.getDatafromHttpUrl(url);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return data;
        }

        @Override
        protected void onPostExecute(String s) {
            setcityData(s);
        }
        public void setcityData(String data){
            JSONObject myObject=null;
            try {
                myObject = new JSONObject(data);
                JSONArray citya = myObject.getJSONArray("data");
                for (int i=0; i<citya.length();i++) {
                    JSONObject cityo = citya.getJSONObject(i);
                    String cityn = cityo.get("State").toString();
                    Log.d("adApi",cityn);
                    Log.d("TextCityName","cityName");
                    if (cityn.equals(cityName)) {
                        String cityp = cityo.get("Population").toString();
                        tvResult.setText(cityp);
                        break;
                    }
                    else
                    {
                        tvResult.setText(cityName + "Not Found");

                    }
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }

        }
    }





}