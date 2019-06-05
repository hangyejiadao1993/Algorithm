/**
 * 贪婪算法 - 集合覆盖问题
 * @author Administrator
 * 集合覆盖问题:

假设存在如下表的需要付费的广播台，以及广播台信号可以覆盖的地区。
如何选择最少的广播台，让所有的地区都可以接收到信号。

广播台	覆盖地区
K1	ID,NV,UT
K2	WA,ID,MT
K3	OR,NV,CA
K4	NV,UT
K5	CA,AZ
…	…
 *
 */

public class A1 {

    public static void main(String[] args){
        //初始化广播台信息
        HashMap<String,HashSet<String>> broadcasts = new HashMap<String,HashSet<String>>();
        broadcasts.put("K1", new HashSet(Arrays.asList(new String[] {"ID","NV","UT"})));
        broadcasts.put("K2", new HashSet(Arrays.asList(new String[] {"WA","ID","MT"})));
        broadcasts.put("K3", new HashSet(Arrays.asList(new String[] {"OR","NV","CA"})));
        broadcasts.put("K4", new HashSet(Arrays.asList(new String[] {"NV","UT"})));
        broadcasts.put("K5", new HashSet(Arrays.asList(new String[] {"CA","AZ"})));

        //需要覆盖的全部地区
        HashSet<String> allAreas = new HashSet(Arrays.asList(new String[] {"ID","NV","UT","WA","MT","OR","CA","AZ"}));
        //所选择的广播台列表
        List<String> selects = new ArrayList<String>();

        HashSet<String> tempSet = new HashSet<String>();
        String maxKey = null;
        while(allAreas.size()!=0) {
            maxKey = null;
            for(String key : broadcasts.keySet()) {
                tempSet.clear();
                HashSet<String> areas = broadcasts.get(key);
                tempSet.addAll(areas);
                //求出2个集合的交集，此时tempSet会被赋值为交集的内容，所以使用临时变量
                tempSet.retainAll(allAreas);
                //如果该集合包含的地区数量比原本的集合多
                if (tempSet.size()>0 && (maxKey == null || tempSet.size() > broadcasts.get(maxKey).size())) {
                    maxKey = key;
                }
            }

            if (maxKey != null) {
                selects.add(maxKey);
                allAreas.removeAll(broadcasts.get(maxKey));
            }
        }
        System.out.print("selects:" + selects);

    }
}
 