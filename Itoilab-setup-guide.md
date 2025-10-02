# 研究室新入生向け開発環境構築ガイド

このガイドでは、研究室で必要な基本的なツールのインストールと設定方法を説明します。

## 目次
- [研究室新入生向け開発環境構築ガイド](#研究室新入生向け開発環境構築ガイド)
  - [目次](#目次)
  - [Visual Studio Code のインストール](#visual-studio-code-のインストール)
    - [推奨拡張機能のインストール](#推奨拡張機能のインストール)
  - [Python のインストール](#python-のインストール)
    - [インストールの確認](#インストールの確認)
  - [Git のインストール](#git-のインストール)
    - [インストールの確認](#インストールの確認-1)
  - [GitHub アカウントの設定](#github-アカウントの設定)
    - [Git の初期設定](#git-の初期設定)
  - [SSH キーの生成と GitHub への登録](#ssh-キーの生成と-github-への登録)
    - [SSHキーの生成](#sshキーの生成)
    - [GitHubへの公開鍵の登録](#githubへの公開鍵の登録)
    - [接続テスト](#接続テスト)
  - [トラブルシューティング](#トラブルシューティング)
    - [よくある問題と解決方法](#よくある問題と解決方法)
    - [参考](#参考)
  - [$\\LaTeX$ の導入](#latexの導入)
    - [texliveのインストール方法](#texliveのインストール方法)
    - [latexmkの設定](#latexmkの設定)
    - [VScode内での環境構築](#vscode内での環境構築)
      - [ユーザースニペット](#ユーザースニペット)
      - [setting.json](#settingjson)

## Visual Studio Code のインストール

![alt text](img/VScode.png)

Visual Studio Code（VSCode）は、プログラミングに適した高機能なテキストエディタです。

1. [Visual Studio Code のダウンロードページ](https://code.visualstudio.com/)にアクセス
2. 「Download for Windows」ボタンをクリック
3. ダウンロードされたインストーラーを実行
4. 以下の項目にチェックを入れることを推奨：
   - 「Code で開く」アクションをエクスプローラーのファイルのコンテキストメニューに追加
   - 「Code で開く」アクションをエクスプローラーのディレクトリのコンテキストメニューに追加
   - PATHへの追加

### 推奨拡張機能のインストール

VSCode起動後、以下の拡張機能をインストールすることを推奨します：

1. Python（Microsoft）
2. Pylance
3. Git Graph
4. Japanese Language Pack for VS Code（日本語表示が必要な場合）
5. Jupyter(直感的にコードを記述・実行するのに便利)

## Python のインストール

Pythonは記述しやすく科学計算に適した機能が充実したプログラミング言語です

![alt text](img/Python.png)

1. [Python公式サイト](https://www.python.org/downloads/)にアクセス
2. 「Download Python 3.x.x」ボタンをクリック（最新のLTS、安定版がおすすめ）
3. ダウンロードされたインストーラーを実行
4. インストール時の重要なオプション：
   - **「Add Python 3.x to PATH」にチェックを入れる**
  (簡単にPythonを呼び出して実行することができるようになります。大事です。)
   - 「Install Now」をクリック
    ![alt text](img/PythonProcess.png)
5. PCを再起動する。(先ほど通したPATHをPCが読み込んでくれます。)

### インストールの確認

1. WindowsキーとRキーを同時に押し、「cmd」と入力してコマンドプロンプトを開く
2. 以下のコマンドを実行：
```
python --version
```
バージョン番号が表示されればインストール成功です。

## Git のインストール

GitはGithubと連携するために入れます。
上手に使うとデータのバックアップ、バージョンの管理を行えます。

![alt text](img/Git.png)

1. [Git公式サイト](https://git-scm.com/downloads)にアクセス
2. 「Windows」をクリックしてインストーラーをダウンロード
3. インストーラーを実行し、以下の設定を推奨：
   - **Default Editor の設定はVisual Studio Codeにするのがおすすめ**
    ![alt text](img/GitProcess2.png)
   - **default branch nameがmasterならばmainに変えてください**
    ![alt text](img/GitProcess.png)
   - **その他はデフォルト設定のまま**
4. PCを再起動

### インストールの確認

コマンドプロンプトで以下のコマンドを実行：
```
git --version
```
バージョン情報が出ればインストール成功です。

## GitHub アカウントの設定

GitHubでは世界中の人がいろいろなプログラムを公開しています。
先ほどインストールしたGitを使うことで、これらのプログラムをまとめてPCにダウロードできます。

1. [GitHub](https://github.com/)にアクセス
2. 「Sign up」をクリックして新規アカウントを作成
3. メールアドレス、ユーザー名、パスワードを設定
4. メール認証を完了

### Git の初期設定

コマンドプロンプトで以下のコマンドを実行（自分の情報に置き換えてください）：
```
git config --global user.name "あなたのGitHubユーザー名"
git config --global user.email "あなたのメールアドレス"
```

## SSH キーの生成と GitHub への登録

### SSHキーの生成

1. コマンドプロンプトで以下のコマンドを実行：
```
ssh-keygen -t ed25519 -C "あなたのメールアドレス"
```
2. 保存場所の指定を求められたら、Enterキーを押して既定の場所に保存
3. **パスフレーズの入力を求められたら、任意のパスフレーズを設定（何も入力せずEnterにするのがおすすめです。後で忘れてしまうので）**

### GitHubへの公開鍵の登録

1. 以下のコマンドで公開鍵の内容を表示：
```
type %USERPROFILE%\.ssh\id_ed25519.pub
```
2. 表示された内容をコピー
3. GitHubにログイン
4. 右上のプロフィールアイコン → Settings → SSH and GPG keys
5. 「New SSH key」をクリック
6. タイトルを入力（例：「Personal Laptop」）
7. 公開鍵をKey欄に貼り付け
8. 「Add SSH key」をクリック

### 接続テスト

コマンドプロンプトで以下のコマンドを実行：
```
ssh -T git@github.com
```
「Hi ユーザー名!」というメッセージが表示されれば成功です。

## Tex のインストール

## トラブルシューティング

### よくある問題と解決方法

1. Python/Gitコマンドが認識されない
   - PCの再起動
   - PATHの確認

2. SSHキー生成時のエラー
   - Git Bashをインストールして実行

3. VSCodeで日本語が文字化けする
   - Japanese Language Packのインストール
   - エンコーディングの設定確認

### 参考
非常に参考になるサイトです。必要になったら参照するのがよいと思います。
- [計算科学のためのWindowsセットアップ](https://zenn.dev/ohno/books/356315a0e6437c)

## $\LaTeX$の導入
### texliveのインストール方法
https://qiita.com/alpaca-honke/items/f30a2d04eedaa3c36a21

texliveのインストールはこれを見ながらやればよい。Windowsの章を参照してlatexをインストールする。

### latexmkの設定
これも先ほどと同様に、この記事を見て`.latexmkrc`ファイルを作り中身を書けばよい。

https://qiita.com/alpaca-honke/items/f30a2d04eedaa3c36a21#latexmkの設定

完全な引用になってしまうが、中身を示しておくと、
```.latexmkrc
#!/usr/bin/env perl
# 先頭行は、Linux用のシバンなので、Windowsでは削除しても構いません。

# 通常の LaTeX ドキュメント用のコマンド
# 今回はupLaTeXを設定してあります。
$latex = 'uplatex %O -kanji=utf8 -no-guess-input-enc -synctex=1 -interaction=nonstopmode %S'; 
# pdfLaTeX 用のコマンド 
$pdflatex = 'pdflatex %O -synctex=1 -interaction=nonstopmode %S'; 
# LuaLaTeX 用のコマンド 
$lualatex = 'lualatex %O -synctex=1 -interaction=nonstopmode %S'; 
# XeLaTeX 用のコマンド 
$xelatex = 'xelatex %O -no-pdf -synctex=1 -shell-escape -interaction=nonstopmode %S'; 
# Biber, BibTeX 用のコマンド 
$biber = 'biber %O --bblencoding=utf8 -u -U --output_safechars %B'; 
$bibtex = 'upbibtex %O %B'; 
# makeindex 用のコマンド 
$makeindex = 'upmendex %O -o %D %S'; 
# dvipdf のコマンド 
$dvipdf = 'dvipdfmx %O -o %D %S'; 
# dvips のコマンド 
$dvips = 'dvips %O -z -f %S | convbkmk -u > %D'; 
$ps2pdf = 'ps2pdf.exe %O %S %D'; 
  
# $pdf_mode ...PDF の作成方法を指定するオプション 
# 0: $latex で .tex -> .dvi するだけ
# 1: $pdflatex で .tex -> .pdf (pdflatexは英文にしか使えない)
# 2: $latex で .tex -> .dvi / $dvips で .dvi -> .ps / $ps2pdf で .ps -> PDF
# 3: $latex で .tex -> .dvi / $dvipdf で .dvi -> PDF 
# 4: $lualatex で .tex -> PDF
# 5: $xelatex で .tex -> .xdv / $xdvipdfmx で .xdv -> PDF
# lualatexしか使わないなら以下行のコメント（#）を外すが、他も使いそうならこのまま
# $pdf_mode = 4; 
  
# PDFビューワ の設定 
# "start %S": .pdf の規定のソフトで表示（Windowsのみ）
# Linuxの場合、"evince %S" を指定してください
$pdf_previewer = "start %S";
```
である。最後の行のpdf_previewerはたぶん設定しなくてよい。

### VScode内での環境構築
#### ユーザースニペット
いい感じのやつを引っ張ってきて使えばよい。ご自由にどうぞ
#### setting.json
設定ファイルで、`.tex`ファイルをどの順にコンパイルするかなどを指定する。石川は昔から下の設定でvscodeをセットアップしている。
```json
{
    "workbench.colorTheme": "GitHub Light",
    "workbench.iconTheme": "material-icon-theme",
    "jupyter.askForKernelRestart": false,
    "qiita-markdown-preview.status": "enable", 
    "latex-workshop.latex.tools": [
        {
            "command": "latexmk",
            "args": [
                "-synctex=1",
                "-interaction=nonstopmode",
                "-file-line-error",
                "-pdf",
                "%DOC%"
            ],
            "name": "latexmk"
        },
        {
            "command": "pdflatex",
            "args": [
                "-synctex=1",
                "-interaction=nonstopmode",
                "-file-line-error",
                "%DOC%"
            ],
            "name": "pdflatex",
            },
            {
                "command": "bibtex",
                "args": [
                    "%DOCFILE%"
                ],
                "name": "bibtex",
            },
            {
                "command": "ptex2pdf",
                "args": [
                    "-interaction=nonstopmode",
                    "-l",
                    "-ot",
                    "-kanji=utf8 -synctex=1",
                    "%DOC%.tex"
                ],
                "name":"ptex2pdf",
            },
           {
                "command": "ptex2pdf",
                "args": [
                    "-l",
                    "-u",
                    "-ot",
                    "-kanji=utf8 -synctex=1",
                    "%DOC%"
                ],
                "name":"ptex2pdf (uplatex)",
            },
            {
                "command": "pbibtex",
                "args": [
                    "-kanji=utf8",
                    "%DOCFILE%"
                ],
                "name": "pbibtex",
            }
     ],
     "latex-workshop.latex.recipes": [
     {
        "name": "ptex2pdf",
        "tools": [
            "ptex2pdf"
        ]
     },
     {
        "name": "ptex2pdf -> pbibtex -> ptex2pdf*2",
        "tools": [
            "ptex2pdf",
            "pbibtex",
            "ptex2pdf",
            "ptex2pdf"
        ]
     },
     {
        "name": "pdflatex -> bibtex -> pdflatex*2",
        "tools": [
            "pdflatex",
            "bibtex",
            "pdflatex",
            "pdflatex"
        ]
     },
     {
        "name": "latexmk",
        "tools": [
            "latexmk"
        ]
     },
     {
        "name": "pdflatex",
        "tools": [
            "pdflatex"
        ]
     },
     {
        "name": "ptex2pdf (uplatex)",
        "tools": [
            "ptex2pdf (uplatex)"
        ]
     },
     {
        "name": "ptex2pdf (uplatex) -> pbibtex -> ptex2pdf (uplatex) *2",
        "tools": [
            "ptex2pdf (uplatex)",
            "pbibtex",
            "ptex2pdf (uplatex)",
            "ptex2pdf (uplatex)"
        ]
     },
     ],
     
     
     "latex-workshop.latexindent.path": "C:\\texlive\\2024\\bin\\windows\\latexindent.exe",
     "latex-workshop.view.pdf.viewer": "tab",
     
     "[tex]": {
        // スニペット補完中にも補完を使えるようにする
        "editor.suggest.snippetsPreventQuickSuggestions": false,
        // インデント幅を2にする
        "editor.tabSize": 2
     },
     
     "[latex]": {
        // スニペット補完中にも補完を使えるようにする
        "editor.suggest.snippetsPreventQuickSuggestions": false,
        // インデント幅を2にする
        "editor.tabSize": 2
     },  
     
     "[bibtex]": {
        // インデント幅を2にする
        "editor.tabSize": 2
     },
}
```
ここで問題になるのが、`"latex-workshop.latexindent.path"`である。一番最初に引用したサイトに載っている方法でlatexをインストールするとlatexindent.exeがインストールされないので、もう一度Tex Live Shellを立ち上げてlatexindentをインストールする必要がある。

ほかにも、`jlisings`など様々なパッケージがインストールされていないことが確認されている。（その代わり最初のインストールは死ぬほど早い（遅い）。なので、コンパイルできなくなったら適宜logを見て必要なパッケージが不足していればインストールする必要がある。


