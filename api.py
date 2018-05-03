from flask import Flask, request
from flask_restful import Resource, Api
from bs_option import BSOption_Delta
import json

app = Flask(__name__)
api = Api(app)

mod_router = { 'bsoption_delta': 'BSOption_Delta' }

class Parser(Resource):
    def get(self, item):
        return mod_router

    def post(self, item):
        print(item)
        print(request.json)
        mod_type = request.json['mod_type']
        mod_func = eval(mod_router[mod_type])
        return mod_func(request.json)

api.add_resource(Parser, '/module/<string:item>')

if __name__ == '__main__':
    app.run(port=5000, debug=True)
