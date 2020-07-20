# 課題4 レポート

bb35319036 半田丈都

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
6 構造体を指定しそこにファイルの数値を配列として格納
55 構造体human_dataにデータが空欄になるまで格納
77 構造体の1から14番目を参照し入力された数字があればID、性別、身長を出力
93 もしIDが一致しデータがあればｊは＋１されるのでプラスされない場合Nodataが出力される
## 入出力結果

PS C:\Users\admin\Documents\GitHub\2020psp2\k04> ./k04
input the filename of sample height:c:\Users\admin\Documents\GitHub\2020psp2\sample\heights.csv
input the filename of sample ID:c:\Users\admin\Documents\GitHub\2020psp2\sample\IDs.csv
Which ID's data do you want? : 45318088
45318088
Male
171.1

PS C:\Users\admin\Documents\GitHub\2020psp2\k04> ./k04
input the filename of sample height:c:\Users\admin\Documents\GitHub\2020psp2\sample\heights.csv
input the filename of sample ID:c:\Users\admin\Documents\GitHub\2020psp2\sample\IDs.csv
Which ID's data do you want? : 1
No data

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴

[comment0720宮下]

課題提出お疲れさまでした！修正点はありません。k04完了です。