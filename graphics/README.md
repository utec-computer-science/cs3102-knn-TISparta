### Graphics

`take-times.cpp` takes time of different executions of KNN and save the results
in `data.in` and `generate-graphics.py` creates a graphic with the data in
`data.in`

### Configuration

* Create a virtual environment
- [Create a virtual environment](https://docs.python.org/3/tutorial/venv.html)

```bash
python3 -m venv venv
```

- Activate the virtual environment

* Windows
```
venv\Scripts\activate.bat
```

* Linux-MacOS
```
source venv/bin/activate
```

- Install dependencies
```
pip install -r requirements.txt
```

### Execution

```bash
make
./run
python generate-graphics.py
```
