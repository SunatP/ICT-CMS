package snp.ict_cms;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.content.res.Configuration;

import java.security.PublicKey;
import java.util.Locale;

import static snp.ict_cms.R.id.regis;


public class Main extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.home);

        Button buttonAbout = findViewById(R.id.regis);
        buttonAbout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Main.this, RegisterActivity.class);
                startActivity(intent);

            }
        });
        Button Login = findViewById(R.id.signin);
        Login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Main.this, LoginActivity.class);
                startActivity(intent);
            }
        });
        Button butonTh = (Button)findViewById(R.id.TH);
        butonTh.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Configuration config = new Configuration();
                config.locale = new Locale("th");
                getResources().updateConfiguration(config, null);
                onCreate(null);
            }
        });
        Button butonEn = (Button)findViewById(R.id.EN);
        butonEn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Configuration config = new Configuration();
                config.locale = Locale.ENGLISH;
                getResources().updateConfiguration(config, null);
                onCreate(null);
            }
        });
    }
}


