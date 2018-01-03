package snp.ict_cms;


import android.annotation.SuppressLint;
import android.app.Activity;
import android.media.MediaCas;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.Toast;
import android.content.Intent;

import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import static snp.ict_cms.R.id.logon;
import static snp.ict_cms.R.layout.login;

/**
 * Created by Acer- on 1/12/2560.
 */

public class LoginActivity  extends Activity {
    public static final String url = "http://10.98.34.141/myweb/login.php";

    public static String result = "";


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // TODO Auto-generated method stub
        super.onCreate(savedInstanceState);
        setContentView(login);


        final Button login = findViewById(logon);
        login.setOnClickListener(new OnClickListener() {

            public void onClick(View arg0) {
                WebPageTask task = new WebPageTask();
                task.execute();
            }
        });
        Button buttonAbout = findViewById(R.id.logon);
        buttonAbout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(LoginActivity.this, DataBase.class);
                startActivity(intent);
            }
        });
    }

    public String login() {
        EditText editText_ID = findViewById(R.id.edittext_ID1);
        EditText editText_Password = findViewById(R.id.edittext_Password1);
        List<NameValuePair> nameValuePairs = new ArrayList<NameValuePair>(2);
        nameValuePairs.add(new BasicNameValuePair("username", editText_ID.getText().toString()));
        nameValuePairs.add(new BasicNameValuePair("password", editText_Password.getText().toString()));
        return postData(url, nameValuePairs);
    }

    public String postData(String url, List<NameValuePair> nameValuePairs) {
        HttpClient httpclient = new DefaultHttpClient();
        HttpPost httppost = new HttpPost(url);
        BufferedReader in = null;
        try {
            httppost.setEntity(new UrlEncodedFormEntity(nameValuePairs));
            HttpResponse response = httpclient.execute(httppost);
            in = new BufferedReader(new InputStreamReader(response.getEntity().getContent()));
            StringBuffer sb = new StringBuffer("");
            String line = "";
            String NL = System.getProperty("line.separator");
            while ((line = in.readLine()) != null) {
                sb.append(line + NL);
            }
            in.close();
            String page = sb.toString();
            return page;

        } catch (ClientProtocolException e) {
            // TODO Auto-generated catch block
        } catch (IOException e) {
            // TODO Auto-generated catch block
        }
        return null;
    }

    private class WebPageTask extends AsyncTask<Void, Void, String> { // TO ECHO system

        @Override
        protected String doInBackground(Void... param) {
            result = login();
            return result;
        }

        @Override
        protected void onPostExecute(String result) {
            if (result.trim().equals("OK")) {
                Toast.makeText(LoginActivity.this, "Log in Fail Try Again!", Toast.LENGTH_LONG).show();
            } else {

                Toast.makeText(LoginActivity.this, "Log in Success!", Toast.LENGTH_SHORT).show();
                Toast.makeText(LoginActivity.this, "This is PROTOTYPE You can't access the DataBase", Toast.LENGTH_LONG).show();
                Toast.makeText(LoginActivity.this, "Please Try Next Semester!", Toast.LENGTH_LONG).show();
            }

        }
    }

}

