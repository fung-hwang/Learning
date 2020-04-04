### startActivity(intent)前判断是否有能接收的应用

```Java
Intent intent = new Intent("Intent.ACTION_VIEW");
intent.setData(Uri.parse("http://www.baidu.com"));
PackageManager pm = getPackageManager();
if (intent.resolveActivity(pm) != null) {
    startActivity(intent);
    }else {
      Log.d(TAG, "onClick:没有响应的应用 ");
      }
```

因为并不清楚用户设备上是否有可以能接受的应用（比如浏览器），`intent.resolveActivity()`可以判断intent是否有能响应的应用，没有则会返回null

>如果设备上没有可接收隐式 Intent 的应用，您的应用将在调用 startActivity() 时崩溃。如需事先验证是否存在可接收 Intent 的应用，请对 Intent 对象调用 resolveActivity()。如果结果为非空，则至少有一个应用能够处理该 Intent，并且可以安全调用 startActivity()。如果结果为空，则您不应使用该 Intent。如有可能，您应禁用调用该 Intent 的功能。
https://developer.android.google.cn/guide/components/intents-common?hl=zh_cn

**至于为什么模拟器明明有浏览器却不能响应，暂时还没有找到原因  
同样的情况出现在了Intent.ACTION_DIAL/CALL上  
而这些intent在之前都是正常的  
2020.04.04**
