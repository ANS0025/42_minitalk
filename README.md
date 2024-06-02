## 概要
minitalkは、UNIXシグナルを使用してクライアントとサーバー間で通信を行い、テキストのやりとりを可能にするプロジェクト。
このプロジェクトは、42東京のカリキュラムの一部であり、学生がプロセス間通信の基本概念を理解することを目的としている。
![image](https://github.com/ANS0025/42_minitalk/assets/75423028/c75ee3bc-e17c-4b2a-b202-360f78d4836f)


## プロジェクトの目的
このプロジェクトの主な目的：
- UNIXシグナルを使用したプロセス間通信の仕組みを理解する
- クライアント-サーバーアーキテクチャを実装する
- シグナルハンドラを適切に設定し、シグナルを処理する方法を学ぶ

このプロジェクトを通して、身につけられるスキル：
- プロセス間通信の基本概念
- シグナルの送受信と処理
- バイナリデータの送信と受信
- マルチプロセス

## 使用方法
1. リポジトリをクローン： ```git clone https://github.com/ANS0025/42_minitalk.git```
2. プロジェクトディレクトリに移動: ```cd 42_minitalk```
3. コンパイル: ```make```
4. サーバープロセスを起動: ```./server```
5. クライアントプロセスからメッセージを送る: ```./client <サーバーのPID>　<メッセージ>```  
クライアントから送信したメッセージはサーバー側のプロセスに標準出力される

## 参考
- [Communicating between processes using signals](https://www.youtube.com/watch?v=PErrlOx3LYE&list=RDCMUC6qj_bPq6tQ6hLwOBpBQ42Q&start_radio=1&rv=PErrlOx3LYE&t=0)
- [Understanding Signals in Linux System](https://www.youtube.com/watch?v=L3XuR-iRysU&list=PLysdvSvCcUhbrU3HhGhfQVbhjnN9GXCq4&index=43)
