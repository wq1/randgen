randgenは標準出力にランダムなバイナリデータを出力するプログラムです。  
zerogenは0x00を出力します。  

引数に出力バイト数を指定することができます。  
単位はK,M,G,T,P,Eが使用できます。  
（桁区切りのカンマ等は使用できません。）  
指定しなければ，標準出力の受取先が終了するまで動作し続けます。  

Windowsだと/dev/urandomや/dev/zeroがないので作りました。


例:  
1Mのダミーファイルを作成する  
zerogen 1M > test.bin

x264にランダムデータを入力する  
randgen | x264 - --demuxer raw --input-res 640x480 --fps 30000/1001 --frames 300 -o test.mp4  
