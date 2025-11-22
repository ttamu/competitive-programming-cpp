# Competitive Programming (C++)

競技プログラミング用のC++環境

## セットアップ

```bash
docker build -t procon-env .
```

## コマンド

| コマンド                 | 説明                                                             |
|----------------------|----------------------------------------------------------------|
| `make up`            | コンテナ起動                                                         |
| `make down`          | コンテナ停止                                                         |
| `make new <target>`  | ファイル作成                                                         |
| `make run [target]`  | 実行（省略時：`main.cpp`、`< file`で入力指定可）                              |
| `make test <target>` | テスト実行（[oj-tools](https://github.com/online-judge-tools/oj)を使用） |

## ディレクトリ構造

```
cpp/
├── src/
│   ├── main.cpp
│   ├── template.cpp
│   └── bin/
│       ├── abc400_d.cpp
│       └── arc198_a.cpp
├── lib/
│   └── atcoder/
├── scripts/
│   └── run.sh
├── testcases/
│   └── abc400_d/
│       ├── sample-1.in
│       └── sample-1.out
├── Makefile
└── Dockerfile
```
