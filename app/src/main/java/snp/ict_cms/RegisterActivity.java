package snp.ict_cms;

import android.app.Activity;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

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

import snp.ict_cms.Main;
import snp.ict_cms.R;
import snp.ict_cms.RegisterActivity;



public class RegisterActivity extends Activity {
    public static final String url = "http://10.98.34.141/myweb/signup.php";
    public static final String url1 = "http://10.98.34.141/myweb/userlist.php";
    public static String result = "";

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        // TODO Auto-generated method stub
        super.onCreate(savedInstanceState);
        setContentView(R.layout.register);

        Button signup;
        signup = findViewById(R.id.signup);
        signup.setOnClickListener(new OnClickListener() {

            public void onClick(View arg0) {
                WebPageTask task = new WebPageTask();
                task.execute();
                finish();

            }
        });
    }

    public String signUp() {
        
        EditText editText_ID = findViewById(R.id.edittext_ID);
        EditText editText_Password = findViewById(R.id.edittext_Password);
        EditText editText_Firstname = findViewById(R.id.edittext_Firstname);
        EditText editText_Lastname = findViewById(R.id.edittext_Lastname);
        EditText editText_Email = findViewById(R.id.edittext_Email);
        EditText editText_Phone = findViewById(R.id.edittext_Phone);
        List<NameValuePair> nameValuePairs = new ArrayList<NameValuePair>(2);
        nameValuePairs.add(new BasicNameValuePair("username",editText_ID.getText().toString()));
        nameValuePairs.add(new BasicNameValuePair("password",editText_Password.getText().toString()));
        nameValuePairs.add(new BasicNameValuePair("firstname",editText_Firstname.getText().toString()));
        nameValuePairs.add(new BasicNameValuePair("lastname",editText_Lastname.getText().toString()));
        nameValuePairs.add(new BasicNameValuePair("phone",editText_Phone.getText().toString()));
        nameValuePairs.add(new BasicNameValuePair("email",editText_Email.getText().toString()));
        return postData(url,nameValuePairs);
    }

    private String postData(String url, List<NameValuePair> nameValuePairs) {
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
        }
            catch (IOException e) {
        }
        return null;
    }

private class WebPageTask extends AsyncTask<Void,Void , String> // TO ECHO system
{
    @Override
    protected String doInBackground(Void... param) {
        result = signUp();
        return result;
    }

    @Override
    protected void onPostExecute(String result) {
            if (result.trim().equals("OK")) {
        Toast.makeText(RegisterActivity.this, "Sign up Fail Try Again!",Toast.LENGTH_LONG).show();
    } else{
        Toast.makeText(RegisterActivity.this, "Sign up Success!",Toast.LENGTH_LONG).show();
            }
        }
    }
}
