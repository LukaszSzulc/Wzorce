for f in $(find . -name '*.h' -or -name '*.cpp'); do
    iconv -f cp1250 -t utf-8 $f > $f.bak
    mv $f.bak $f
done
