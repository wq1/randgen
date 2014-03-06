randgenは標準出力にランダムな，あるいは0x00なバイナリデータを出力するプログラムです。  

Usage: randgen [-s size] [-z]

-s sizeを指定しまます。
単位にはK,M,G,T,P,Eが使用できます。  
（桁区切りのカンマ等は使用できません。）  
指定しなければ，標準出力の受取先が終了するまで動作し続けます。  

-z ランダムデータではなく0x00を出力します。

Windowsだと/dev/urandomや/dev/zeroがないので作りました。


例:  
1MiBのダミーファイルを作成する  
zerogen -zs 1M > test.bin

x264にランダムデータを入力する  
randgen | x264 - --demuxer raw --input-res 640x480 --fps 30000/1001 --frames 300 -o test.mp4  
