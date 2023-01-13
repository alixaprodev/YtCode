package com.alixaprodev.quizapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    private Button buttonFalse;
    private Button buttonTrue;
    private TextView question;
    private ImageButton nextButton;
    private ImageButton prButton;
    private int currentIndex=0;

    private Question [] questionBank = new Question[]{
            new Question(R.string.question1,false),
            new Question(R.string.question2,false),
            new Question(R.string.question3,false),
            new Question(R.string.question4,true),
            new Question(R.string.question5,true),
            new Question(R.string.question6,true)
    };



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);



       question = findViewById(R.id.question);
       buttonFalse = findViewById(R.id.btn_false);
       buttonTrue = findViewById(R.id.btn_true);
       nextButton= findViewById(R.id.next_btn);
       prButton = findViewById(R.id.pr_btn);


        buttonFalse.setOnClickListener(this);
        buttonTrue.setOnClickListener(this);
        nextButton.setOnClickListener(this);
        prButton.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.btn_false:
                checkQuestion(false);
                break;
            case R.id.btn_true:
                checkQuestion(true);
                break;
            case R.id.next_btn:
                currentIndex= (currentIndex+1)%questionBank.length;
                updateQuestion();
                break;
            case R.id.pr_btn:
                currentIndex= (currentIndex+questionBank.length-1)%questionBank.length;
                updateQuestion();

        }
    }
    private void updateQuestion(){
        question.setText(questionBank[currentIndex].getAnswerResID());
    }
    private void checkQuestion(boolean userAns){
        boolean orignalAns = questionBank[currentIndex].isAnswerTrue();
        int toastMessage=0;
        if (userAns==orignalAns)
            toastMessage=R.string.correctAnswer;
        else toastMessage= R.string.wrongAnswer;
        Toast.makeText(this, toastMessage, Toast.LENGTH_SHORT).show();
    }

}